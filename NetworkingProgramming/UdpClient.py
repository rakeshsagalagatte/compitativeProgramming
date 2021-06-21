import socket
import sys

targetHost = '127.0.0.1'
targetPort = 80

if len(sys.argv) > 1:
    targetHost = sys.argv[1]

print('Connecting to ' + targetHost + ' .....')

#create a socket object 
clientUDP = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

#send some data
clientUDP.sendto(b"AABBCC", (targetHost, targetPort))

# receive data
data, addr = clientUDP.recvfrom(4096)
clientUDP.close()
print(data)
