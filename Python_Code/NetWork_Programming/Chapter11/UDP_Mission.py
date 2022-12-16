def server():
    # server
    import socket
    import sys
    import os

    port = 4000
    host = ''
    s_sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    s_sock.bind((host, port))
    # s_sock.listen(1)

    # c_sock, addr = s_sock.accept()
    data, addr = s_sock.recvfrom(1024)
    print('Connected from', addr)
    s_sock.sendto("OK".encode(), addr)

    while True:
        data, addr = s_sock.recvfrom(1024)
        data.decode()
        key = data[:4]
        content = data[4:].strip()
        print("key=", key, 'content=', content)

        if key == "file":
            fileSize = os.path.getsize('D:/' + content)
            s_sock.sendto(str(fileSize).encode(), addr)
            with open("D:/" + content, 'rb') as f:
                while f:
                    s_sock.sendto(f, addr)
                    s_sock.sendto("EoF".encode())
                print(content + ' Sending complete')
            continue

        elif key == "chat":
            print(data)
            s_sock.sendto(input("Response: ").encode(), addr)
            continue

        elif key == "stop":
            break

        else:
            s_sock.send("Wrong input".encode(), addr)

    s_sock.close()

def client():
    # server
    import socket

    s_sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    # host = "localhost"
    # port = 2600
    data, addr = s_sock.recvfrom(1024)

    # s_sock.connect((host, port))
    print("server - " + addr.decode())
    print("Use chat or file or stop")

    while True:
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
            print(type(datasize))
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

server()