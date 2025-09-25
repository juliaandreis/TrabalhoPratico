#julia andreis e tobias klein

import socket
import threading

HOST = '192.168.1.108' # IP do servidor # 192.168.100.237 (PC Tobias) # 192.168.1.108 (PC Julia)
PORT = 50000     # porta do servidor

def receive_messages(client_socket):
    while True:
        try:
            message = client_socket.recv(2048).decode('utf-8')
            if not message:
                break
            # imprime a mensagem e redesenha o prompt de input na linha de baixo
            print(f"\r{message}\n> ", end="")
        except:
            print("\r[ERRO] Conexão com o servidor perdida.")
            break
    client_socket.close()

def send_messages(client_socket):
    while True:
        try:
            message = input("> ")
            client_socket.send(message.encode('utf-8'))
            if message.lower() == "/sair":
                pass
        except:
            break
    client_socket.close()

def start_client():
    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    try:
        client.connect((HOST, PORT))
    except Exception as e:
        return print(f"Não foi possível se conectar ao servidor: {e}")

    # valida nome de usuário
    while True:
        username = input("Digite o seu nome de usuário: ")
        if not username:
            print("Nome de usuário não pode ser vazio.")
            continue
        
        client.send(username.encode('utf-8'))
        response = client.recv(2048).decode('utf-8')

        if response == "OK":
            print("Login realizado com sucesso!\n")
            break
        elif response == "NOT_UNIQUE":
            print("Este nome de usuário já está em uso. Tente outro.")
        else:
            print("Nome de usuário inválido.")

    thread_receive = threading.Thread(target=receive_messages, args=(client,), daemon=True)
    thread_receive.start()
    
    thread_send = threading.Thread(target=send_messages, args=(client,))
    thread_send.start()
    
    thread_send.join()

    print("Você foi desconectado.")

if __name__ == "__main__":
    start_client()