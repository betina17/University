import socket

def run_client(server_host='127.0.0.1', server_port=5000):
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as client_socket:
        client_socket.connect((server_host, server_port))

        client_number = input("Enter a number (1-100): ")
        client_socket.send(client_number.encode())

        response = int(client_socket.recv(1024).decode())
        print(f"Server's response: {response}")

        if response == 0:
            print("Congratulations! You guessed the server's number.")

if __name__ == "__main__":
    run_client()
