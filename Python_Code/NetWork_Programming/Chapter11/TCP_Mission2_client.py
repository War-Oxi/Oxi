#client
import socket

s_sock = socket.socket()
host = "localhost"
port = 2500

s_sock.connect((host, port))
print("server - " + s_sock.recv(1024).decode())
print("Use chat or file or stop")

while True:
    msg = input("Ask: ")
    key = msg[:4]
    content = msg[4:].strip()

    if key == "chat":
        s_sock.send(msg.encode())
        print(s_sock.recv(1024).decode())
        continue
    elif key == "file":
        s_sock.send(msg.encode())
        with open('D:/receive/' + content, 'wb') as f:
            while True:
                data = s_sock.recv(8192)
                if not data:
                    break
                elif data[-3:].decode() == "EoF":
                    f.write(data[:-3])
                    break
                f.write(data)  # ???
            print(content + ' Download completed')
        continue
    elif key == "stop":
        break
    else:
        print("Use chat or file or stop ")

s_sock.close()
print("Connection closed")
