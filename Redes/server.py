#julia andreis e tobias klein

import socket
import threading

HOST = '0.0.0.0'
PORT = 50000

clients = {}
lock = threading.Lock()

def listar_menu():
    # usuários que estão em um chat privado não aparecem no menu
    with lock:
        menu_users = [user for user, data in clients.items() if data["status"] == "menu"]
        if not menu_users:
            return
        
        message = "\n[USUÁRIOS DISPONÍVEIS]:\n " + "\n ".join(menu_users)

        for _, data in clients.items():
            if data["status"] == "menu":
                try:
                    data["socket"].send(message.encode("utf-8"))
                except:
                    pass

def client_connection(sock, addr):
    print(f"[NOVA CONEXÃO] {addr}")
    username = None
    try:
        # login
        while True:
            username_candidate = sock.recv(2048).decode("utf-8").strip()
            if not username_candidate:
                sock.send(b"NOT_VALID")
                continue
            with lock:
                if username_candidate in clients:
                    sock.send(b"NOT_UNIQUE")
                else:
                    username = username_candidate
                    clients[username] = {"socket": sock, "status": "menu", "partner": None}
                    sock.send(b"OK")
                    break

        print(f"[LOGIN] {username} de {addr} entrou.")
        sock.send(f"Bem-vindo, {username}!\nPara convidar alguém, digite o nome do usuário.".encode("utf-8"))
        listar_menu()

        while True:
            data = sock.recv(2048)
            if not data:
                break
            message = data.decode("utf-8").strip()

            with lock:
                user_data = clients.get(username)
                if not user_data: 
                    break # usuário pode ter sido desconectado
                status = user_data["status"]

            # estando no menu:
            if status == "menu":
                if message.lower().startswith(("/aceitar", "/recusar")):
                    resposta = message.split()
                    if len(resposta) == 2:
                        answer, destinatario = resposta[0].lower(), resposta[1]
                        
                        with lock:
                            if user_data.get("partner") == destinatario and destinatario in clients:
                                if answer == "/aceitar":
                                    clients[username]["status"] = "chat"
                                    clients[destinatario]["status"] = "chat"
                                    clients[username]["partner"] = destinatario
                                    clients[destinatario]["partner"] = username
                                    clients[destinatario]["socket"].send(f"[CONECTADO] {username} aceitou seu convite! O chat começou.".encode("utf-8"))
                                    sock.send(f"[CONECTADO] Você aceitou o convite. O chat com {destinatario} começou.".encode("utf-8"))
                                    print(f"[CHAT INICIADO] entre {username} e {destinatario}.")
                                else:
                                    clients[destinatario]["socket"].send(f"[INFO] {username} recusou seu convite.".encode("utf-8"))
                                    sock.send(f"[INFO] Você recusou o convite de {destinatario}.".encode("utf-8"))
                                    clients[username]["partner"] = None
                                    clients[destinatario]["partner"] = None
                            else:
                                sock.send("[ERRO] Convite inválido ou expirado.".encode("utf-8"))       
                    else:
                        sock.send("[ERRO] Comando inválido. Use /aceitar <usuario> ou /recusar <usuario>".encode("utf-8"))
                else:
                    destinatario = message
                    with lock:
                        if destinatario in clients and clients.get(destinatario, {}).get("status") == "menu":
                            invite_msg = f"[CONVITE] {username} quer conversar com você.\nDigite /aceitar {username} ou /recusar {username}"
                            clients[destinatario]["socket"].send(invite_msg.encode("utf-8"))
                            clients[destinatario]["partner"] = username
                            sock.send(f"[INFO] Convite enviado para {destinatario}. Aguarde...".encode("utf-8"))
                        else:
                            sock.send(f"[ERRO] Usuário '{destinatario}' não encontrado ou está ocupado.".encode("utf-8"))

            # no chat privado:
            elif status == "chat":
                if message.lower() == "/sair":
                    partner_left = False
                    with lock:
                        partner_name = user_data.get("partner")
                        if partner_name and partner_name in clients:
                            clients[username]["status"] = "menu"
                            clients[username]["partner"] = None
                            clients[partner_name]["status"] = "menu"
                            clients[partner_name]["partner"] = None
                            
                            clients[partner_name]["socket"].send(f"[INFO] {username} saiu do chat. Você voltou para o menu.".encode("utf-8"))
                            sock.send("[INFO] Você saiu do chat e voltou para o menu.".encode("utf-8"))
                            
                            print(f"[CHAT ENCERRADO] entre {username} e {partner_name}.")
                            partner_left = True
                    
                    if partner_left:
                        listar_menu()
                
                # enviar mensagem no chat
                else:
                    with lock:
                        partner_name = user_data.get("partner")
                        if partner_name and partner_name in clients:
                            partner_socket = clients[partner_name]["socket"]
                            partner_socket.send(f"[{username}]: {message}".encode("utf-8"))
                        else:
                            clients[username]["status"] = "menu"
                            clients[username]["partner"] = None
                            sock.send("[INFO] Seu parceiro de chat desconectou. Você voltou ao menu.".encode("utf-8"))

    except (ConnectionResetError, ConnectionAbortedError):
        print(f"[AVISO] Conexão com {addr} perdida.")
    except Exception as e:
        print(f"[ERRO] {addr}: {e}")

    finally:
        print(f"[DESCONECTADO] {addr}")
        partner_disconnected = False
        with lock:
            if username and username in clients:
                partner = clients[username].get("partner")
                if partner and partner in clients and clients[partner].get("status") == "chat":
                    clients[partner]["socket"].send(f"[INFO] {username} se desconectou. Você voltou para o menu.".encode("utf-8"))
                    clients[partner]["status"] = "menu"
                    clients[partner]["partner"] = None
                    partner_disconnected = True
                
                del clients[username]
        
        if partner_disconnected:
            listar_menu()

def start_server():
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind((HOST, PORT))
    server.listen()
    print(f"[SERVIDOR] Escutando em {HOST}:{PORT}")
    while True:
        client_socket, addr = server.accept()
        threading.Thread(target=client_connection, args=(client_socket, addr), daemon=True).start()

if __name__ == "__main__":
    start_server()