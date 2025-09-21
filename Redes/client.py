import socket
import threading

# Configurações do cliente
HOST = '191.4.252.159'  # IP do servidor
PORT = 5000         # Porta do servidor

def receive_messages(client_socket):
    """Recebe e imprime mensagens enviadas pelo servidor."""
    while True:
        try:
            message = client_socket.recv(1024).decode('utf-8')
            if message:
                print("\r" + message + "\n> ", end="")
            else:
                break
        except:
            print("Conexão encerrada pelo servidor.")
            break

def start_client():
    """Conecta ao servidor e envia mensagens digitadas."""
    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client.connect((HOST, PORT))

    # Thread para receber mensagens em paralelo
    threading.Thread(target=receive_messages, args=(client,), daemon=True).start()

    print("Conectado ao chat. Digite suas mensagens e pressione Enter.")
    while True:
        msg = input("> ")
        if msg.lower() == "/sair":
            break
        client.send(msg.encode('utf-8'))

    client.close()

if __name__ == "__main__":
    start_client()