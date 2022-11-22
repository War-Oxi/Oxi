

# server
import socket
import sys

# BUFSIZE = 1024

port = 2500
s_sock = socket.socket()
host = ""
s_sock.bind((host, port))
s_sock.listen(1)

print('Waiting for connection....')

c_sock, addr = s_sock.accept()
print('Connected from', addr)
msg = c_sock.recv(1024)
print(msg.decode())
filename = input('File name to send(c:/test/sample.bin): ')
# filename = c_sock.recv(BUFSIZE) #
print(f"Sending '{filename}'")
fn = filename.split('/')

c_sock.sendall(fn[-1].encode())

with open(filename, 'rb') as f:
    c_sock.sendfile(f, 0)

    #data = f.read()
    #while data:
    # c_sock.sendall(data)
    # data = f.read()

print('Sending complete')
c_sock.close()