import socket, threading


server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
server.bind((("192.168.86.26"), 20))

server.listen(5)

def client_handler(client_socket):
    request = client_socket.recv(100)
    requestDecoded = request.decode('utf-8')
    print ("Received:" + requestDecoded)
    client_socket.close()

while True:
    client, addr = server.accept()
    print ("Accepting connection from " + str(addr[0]) + str(addr[1]))
    servert = threading.Thread(target=client_handler, args=(client,))
    servert.start()