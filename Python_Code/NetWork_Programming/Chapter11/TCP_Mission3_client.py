#client
import socket

s_sock = socket.socket()
host = "localhost"
port = 2600

s_sock.connect((host, port))
print("server - " + s_sock.recv(1024).decode())
print("Use chat or file or stop")

while True:
    msg = input("Ask: ")
    key = msg[:4]
    content = msg[4:].strip()
    received_data = 0
    s_sock.send(msg.encode())
    if key == "chat":
        # s_sock.send(msg.encode())
        print(s_sock.recv(1024).decode())
        continue
    elif key == "file":
        # s_sock.send(msg.encode())

        datasize = int(s_sock.recv(1024).decode())
        print(type(datasize))
        print(f"datasize = {datasize}")
        with open('D:/receive/' + content, 'wb') as f:
            while True:
                data = s_sock.recv(8192)
                received_data += len(data)
                if not data:
                    break
                # elif data[-3:].decode() == "EoF":
                #     f.write(data[:-3])
                #     break
                elif datasize <= received_data:
                    print(f"received_data => {received_data}")
                    print("datasize >= received_data")
                    break
                f.write(data)
            print(content + " Download completed")
        continue
    elif key == "stop":
        # s_sock.send(msg.encode())
        break
    else:
        received_msg = s_sock.recv(1024).decode()
        print(received_msg)
        print("Use chat or file or stop ")

s_sock.close()
print("Connection closed")
