#julia andreis e tobias klein

import socket
import threading

HOST = '0.0.0.0'
PORT = 50000

connections = []
clients = {}  #{username: socket}


"""
def sendMenu(sender_socket):
    #Envia o menu para todos os clientes.
    for client in connections:
        if client != sender_socket:
            try:
                for clientName in clients:
                    client.send("teste".encode('utf-8'))
                    client.send(f"{clientName}")
            except:
                connections.remove(client) #remove clientes que não respondem
"""

def users_list():
    # nomes on-line
    users = list(clients.keys())
    lista = "[USUÁRIOS CONECTADOS] " + ", ".join(users)
    for sock in connections:
        try:
            sock.send(lista.encode('utf-8'))
        except:
            pass  # se der erro, o handle_client já remove

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
        username = client_socket.recv(2048).decode('utf-8').strip()
        clients[username] = client_socket
        connections.append(client_socket)
        print(f"[LOGIN] {username} de {addr}")
        client_socket.send(f"Bem-vindo, {username}! Use: DESTINATARIO: mensagem".encode('utf-8'))
        
        users_list()
       
        while True:    
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