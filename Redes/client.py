#julia andreis e tobias klein

import socket
import threading
import time

# Configurações do cliente
HOST = '192.168.1.108' # IP do servidor
PORT = 50000           # Porta do servidor

def receive_messages(client_socket):
    while True:
        try:
            message = client_socket.recv(2048).decode('utf-8')
            if message:
                print("\r" + message + "\n> ", end="")
            else:
                break
        except:
            print("Conexão encerrada pelo servidor.")
            client_socket.close()
            break
        
def send_messages(client_socket): 
    while True:
        try:
            message = input("> ")
            if message.lower() == "/sair":
                break
            client_socket.send(message.encode('utf-8'))
        except:
            print("Erro ao enviar mensagem.")
            break
    client_socket.close()


def start_client():
    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    try:
        client.connect((HOST, PORT))
    except:
        return print('\nNão foi possível se conectar ao servidor!\n')

    username = input('Digite o seu usuário > ')
    client.send(username.encode('utf-8'))
    
    thread_receive = threading.Thread(target=receive_messages, args=(client,), daemon=True)
    thread_receive.start()

    thread_send = threading.Thread(target=send_messages, args=(client,), daemon=True)
    thread_send.start()

    while True:
        if not thread_receive.is_alive() or not thread_send.is_alive():
            break
        time.sleep(1) # Impede o loop de consumir 100% da CPU
    
    client.close()
    print("Você foi desconectado.")

if __name__ == "__main__":
    start_client()