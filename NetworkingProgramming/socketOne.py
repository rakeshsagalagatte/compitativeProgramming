import socket
import sys

targetHost = 'www.google.com'
targetPort = 80

if len(sys.argv) > 1:
    targetHost = sys.argv[1]

print('Connecting to ' + targetHost + ' ....')
#create a socket object
client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# connect the client
client.connect((targetHost,targetPort))

# send some data
client.send(b'GET / HTTP/1.1\r\nHost: sit.ac.in\r\n\r\n' )

# receive some data
response = client.recv(4096)
print(socket.AF_INET)
client.close()

print(response)