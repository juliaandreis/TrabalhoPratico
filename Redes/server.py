import socket
import threading

HOST = '0.0.0.0'
PORT = 50000

connections = []
clients = {}  # {username: socket}

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

    try:
        username = client_socket.recv(2048).decode('utf-8').strip()
        clients[username] = client_socket
        connections.append(client_socket)
        print(f"[LOGIN] {username} de {addr}")
        client_socket.send(
            f"Bem-vindo, {username}! Use: DESTINATARIO: mensagem".encode('utf-8')
        )

        while True:
            data = client_socket.recv(2048)
            if not data:
                break
            msg = data.decode('utf-8').strip()

            if ':' in msg:
                destination_name, text = msg.split(':', 1)
                destination_name = destination_name.strip()
                text = text.strip()
                full_message = f"{username}: {text}".encode('utf-8')
                send_to_user(destination_name, full_message, client_socket)
            else:
                client_socket.send(
                    b"[SERVIDOR] Formato incorreto. Use DESTINATARIO: mensagem"
                )

    except Exception as e:
        print(f"[ERRO] {addr}: {e}")

    finally:
        print(f"[DESCONECTADO] {addr}")
        if client_socket in connections:
            connections.remove(client_socket)
        # Só tenta remover se username foi realmente definido
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