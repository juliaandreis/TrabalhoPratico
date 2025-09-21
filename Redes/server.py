
import socket
import threading

# Configurações do servidor
HOST = '0.0.0.0'   # Permite clientes de outras máquinas
PORT = 5000        # Porta do servidor

# Lista para armazenar os clientes conectados
connections = []

clients = {}

def broadcast(message, sender_socket):
    """Envia a mensagem para todos os clientes, exceto quem enviou."""
    for client in connections:
        if client != sender_socket:
            try:
                client.send(message)
            except:
                # Remove clientes que não respondem
                connections.remove(client)

def handle_client(client_socket, addr):
    global clients
    """Gerencia a comunicação com um cliente específico."""
    print(f"[NOVA CONEXÃO] {addr} conectado.")
    ip = addr[0]
    porta = addr[1]
    #print(f"{ip} teste {porta}")
    #print(f"{client_socket}")

    boolConectado = 0

    while True:
        try:
            message = client_socket.recv(1024)
            if not boolConectado:
                boolConectado = not boolConectado
                clients = {
                    "ip": addr[0],
                    "porta": addr[1],
                    "nome": message
                }
                print(f"{clients}")

            if not message:
                break
            broadcast(message, client_socket)
        except:
            break
    print(f"[DESCONECTADO] {addr} saiu.")
    connections.remove(client_socket)
    client_socket.close()

def start_server():
    """Inicia o servidor e aceita conexões."""
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind((HOST, PORT))
    server.listen()
    print(f"[SERVIDOR] Escutando em {HOST}:{PORT}")

    while True:
        client_socket, addr = server.accept()
        connections.append(client_socket)
        thread = threading.Thread(target=handle_client, args=(client_socket, addr))
        thread.start()

if __name__ == "__main__":
    start_server()