# server
import socket
import sys

port = 2600
host = ""
s_sock = socket.socket()
s_sock.bind((host, port))
s_sock.listen(1)

c_sock, addr = s_sock.accept()
print('Connected from', addr)
c_sock.send("OK".encode())

while True:
    msg = c_sock.recv(1024).decode()
    key = msg[:4]
    content = msg[4:].strip()
    if not msg:
        print(f"connection closed...")
        break
    print("key=", key, 'content=', content)

    if key == "chat":
        print(msg)
        c_sock.send(input("Response: ").encode())
        continue

    elif key == "file":
        with open("D:/" + content, 'rb') as f:
            c_sock.sendfile(f, 0)
            # c_sock.send("EoF".encode())
            print(content + ' Sending complete')
        continue

c_sock.close()
