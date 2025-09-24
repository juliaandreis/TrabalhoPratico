#julia andreis e tobias klein

import socket
import threading

HOST = '0.0.0.0'
PORT = 50000

connections = []
clients: dict[str, dict[str, object]] = {}  #{username: socket, status}

clients_lock = threading.Lock()

def users_list():
    """
    Cria uma lista de usuários conectados e a envia para todos
    os clientes que estão no estado 'menu'.
    """
    with clients_lock:
        if not clients:
            lista = "[SERVIDOR] Nenhum outro usuário conectado."
        else:
            users = list(clients.keys())
            lista = "\n[USUÁRIOS CONECTADOS]:\n " + "\n ".join(users)

        #.items() retorna a chave (user) e o valor (dicionário com socket/status)
        for _, client_data in clients.items():
            if client_data["status"] == "menu":
                try:
                    client_data["socket"].send(lista.encode('utf-8'))
                except:
                    pass #se der erro, o handle_client já remove

def send_to_user(destination_name, message, sender_socket):
    dest_socket = clients.get(destination_name)
    if dest_socket and dest_socket != sender_socket:
        try:
            dest_socket.send(message)
        except:
            print(f"[ERRO] Falha ao enviar para {destination_name}")

def handle_client(client_socket, addr):
    print(f"[NOVA CONEXÃO] {addr} conectado.")
    username = None
    destination_name = None

    try:
        while True:
            username = client_socket.recv(2048).decode('utf-8').strip()
            if not username or username in clients:
                client_socket.send(f"NOT".encode('utf-8'))
            else:
                client_socket.send(f"OK".encode('utf-8'))
                clients[username] = {
                    "socket": client_socket,
                    "status": "menu"
                    }
                print(clients.keys())
                break

        connections.append(client_socket)
        print(f"[LOGIN] {username} de {addr}")
        client_socket.send(f"Bem-vindo, {username}! Use: DESTINATARIO: mensagem".encode('utf-8'))

        while True:
            if clients[username]["status"] == "menu":
                users_list()
                destination_name = data = client_socket.recv(2048).decode('utf-8').strip()
                if destination_name in clients and destination_name != username:
                    clients[username]["status"] = "chat"
                    client_socket.send(b'True')

            data = client_socket.recv(2048)
            if not data:
                break
            message = data.decode('utf-8').strip()

            if ':' in message:
                print(f"[MENSAGEM] {username} está enviando uma mensagem para {destination_name}")
                destination_name, text = message.split(':', 1)
                destination_name = destination_name.strip()
                text = text.strip()
                full_message = f"{username}: {text}".encode('utf-8')
                send_to_user(destination_name, full_message, client_socket)
                print(f"[ENVIADO] {username} enviou uma mensagem para {destination_name}")
            else:
                client_socket.send(b"[SERVIDOR] Formato incorreto. Use DESTINATARIO: mensagem")

    except Exception as e:
        print(f"[ERRO] {addr}: {e}")

    finally:
        print(f"[DESCONECTADO] {addr}")
        if client_socket in connections:
            connections.remove(client_socket)
        #só tenta remover se username foi realmente definido
        if username and username in clients:
            del clients[username]
        client_socket.close()

def start_server():
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind((HOST, PORT))
    server.listen()
    print(f"[SERVIDOR] Escutando em {HOST}:{PORT}")

    while True:
        client_socket, addr = server.accept()
        threading.Thread(target=handle_client, args=(client_socket, addr), daemon=True).start()

if __name__ == "__main__":
    start_server()