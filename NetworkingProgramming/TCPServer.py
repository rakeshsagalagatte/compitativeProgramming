import socket
import threading

bind_ip = '0.0.0.0'
bind_port = 9999

# Create server 
server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

server.bind((bind_ip, bind_port))

server.listen(5)

print('[*] Listening on ' + str(bind_ip) + ':' + str(bind_port))

# this is our client-handling thread 
def handle_client(client_socket):

    #print the what client sends 
    request = client_socket.recv(1024)

    print(b'[*] Received: '+ request)

    #send back a packet 
    client_socket.send(b'ACK!')

    client_socket.close()

while True:
    client,addr = server.accept()

    print('[*] Accepted connection from: ' + str(addr[0]) + ':' + str(addr[1]))

    # spin up our client thread to handle incoming data
    client_handler = threading.Thread(target=handle_client, args=(client, ))
    client_handler.start()