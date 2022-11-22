import socket

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.connect(('localhost', 3300))
print(sock.recv(1024).decode())
sock.close()