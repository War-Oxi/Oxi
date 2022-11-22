import socket
bufferSize = 1024
port = 2500

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
msg = "Hello UDP server"
sock.sendto(msg.encode(),('localhost', port))
data, addr = sock.recvfrom(bufferSize)
print("Server says:", data.decode())