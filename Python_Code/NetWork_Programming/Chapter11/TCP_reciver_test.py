#server
import socket

s_sock = socket.socket()
host = "localhost"
port = 3200

s_sock.connect((host, port))
s_sock.send("OK".encode())

## 파일 이름 보내는 것을 구현
filename = input('File name to receive(c:/test/sample.bin): ')
s_sock.send(filename.encode())

fn = s_sock.recv(1024).decode()

with open('d:/'+fn, 'wb') as f:
    print('file opened')
    print('receiving file...')
    while True:
        data = s_sock.recv(8192)
        if not data:
            break
        f.write(data)

print('Download complete')
s_sock.close()
print('Connection closed')