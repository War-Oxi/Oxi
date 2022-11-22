import socket

s_sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
host = "localhost"
port = 4000
s_sock.sendto("123123".encode(), (host, port))
data, addr = s_sock.recvfrom(1024)

# s_sock.connect((host, port))
print("server - ", addr)

while True:
    print("Use chat or file or stop")
    msg = input("Ask: ")
    key = msg[:4]
    content = msg[4:].strip()
    received_data = 0
    s_sock.sendto(msg.encode(), addr)
    if key == "chat":
        # s_sock.send(msg.encode())
        print(s_sock.recvfrom(1024))
        continue
    elif key == "file":
        # s_sock.send(msg.encode())
        data, addr = s_sock.recvfrom(1024)
        datasize = int(data.decode())
        # print(type(datasize))
        print(f"datasize = {datasize}")
        with open('D:/receive/' + content, 'wb') as f:
            while True:
                data, addr = s_sock.recvfrom(8192)
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
            print(content + ' Download completed')
        continue
    elif key == "stop":
        # s_sock.send(msg.encode())
        break
    else:
        received_msg, addr = s_sock.recvfrom(1024)
        print(received_msg.decode())
        print("Use chat or file or stop ")

s_sock.close()
print("Connection closed")