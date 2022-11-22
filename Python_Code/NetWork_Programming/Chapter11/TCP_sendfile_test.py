

# server
import socket
import sys

# BUFSIZE = 1024

port = 3200
s_sock = socket.socket()
host = ""
s_sock.bind((host, port))
s_sock.listen(1)

print('Waiting for connection....')

c_sock, addr = s_sock.accept()
print('Connected from', addr)
msg = c_sock.recv(1024)
print(msg.decode())

## 파일 이름을 받는 것을 구현
filename = c_sock.recv(1024).decode()
# print("받은 파일 명 : ", filename.decode())
print(f"Sending '{filename}'")


# filename = input('File name to send(c:/test/sample.bin): ')
# filename = c_sock.recv(BUFSIZE) #
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