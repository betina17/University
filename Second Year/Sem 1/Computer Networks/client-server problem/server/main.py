import socket
import threading
import select
import random


server_running = True


def handle_client(client_socket, server_number, shutdown_server):
    global server_running
    while True:
        try:
            message = client_socket.recv(1024)
            if not message:
                break

            client_number = int(message.decode())
            response = ''
            if client_number == server_number:
                response = '0'
                server_running = False
                shutdown_server.set()
            elif client_number < server_number:
                response = '-1'
            else:
                response = '+1'

            client_socket.send(response.encode())

            if response == '0':
                break
        except Exception as e:
            print(f"An error occurred: {e}")
            break

    client_socket.close()


def run_server(host='0.0.0.0', port=5000):
    global server_running
    server_number = random.randint(1, 100)
    print(f"Server's number: {server_number}")

    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    server_socket.bind((host, port))
    server_socket.listen(3)

    sockets_list = [server_socket]
    shutdown_server = threading.Event()

    try:
        while server_running:
            read_sockets, _, _ = select.select(sockets_list, [], [], 1)

            for notified_socket in read_sockets:
                if notified_socket == server_socket:
                    client_socket, client_address = server_socket.accept()
                    print(f"Accepted new connection from {client_address[0]}:{client_address[1]}")
                    threading.Thread(target=handle_client, args=(client_socket, server_number, shutdown_server)).start()

            if shutdown_server.is_set():
                break

    finally:
        server_socket.close()
        print("A client has guessed the server's number. Server stopped.")


if __name__ == "__main__":
    run_server()
