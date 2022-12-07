def server():
    import sys
    import socket
    import os
    import time
    BUFSIZE = 1024 * 8
    port = 4200
    s_sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    host = ""
    s_sock.bind((host, port))

    data, addr = s_sock.recvfrom(1024)
    print('Connected from', addr)
    s_sock.sendto("OK".encode(), addr)

    while True:
        data, addr = s_sock.recvfrom(1024)
        data = data.decode()
        key = data[:4]
        content = data[4:].strip()
        print("key=", key, 'content=', content)

        if key == "file": #먼저 보내기
            fileSize = os.path.getsize('D:/' + content)
            print(f"filesize => {fileSize}")
            s_sock.sendto(str(fileSize).encode(), addr)  #
            with open("D:/" + content, 'rb') as fp:
                data = fp.read(BUFSIZE)
                while data:
                    s_sock.sendto(data, addr)
                    # time.sleep(0.01)
                    data, addr = s_sock.recvfrom(1024)
                    if data.decode() == "ACK":
                        data = fp.read(BUFSIZE)
                        continue
                    else:
                        print("123123")
                        time.sleep(0.02)

                print(content + ' Sending complete')
            continue

        elif key == "chat":
            print(f"client => {content}")
            s_sock.sendto(input("Response: ").encode(), addr)
            continue

        elif key == "stop":
            break

        else:
            s_sock.sendto("Wrong input".encode(), addr)

    s_sock.close()


def client():
    # server
    import socket

    s_sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    host = "localhost"
    port = 4200
    s_sock.sendto("Connect plz".encode(), (host, port))
    data, addr = s_sock.recvfrom(1024)

    print("server - ", addr)

    while True:
        print("Use chat or file or stop")
        msg = input("Ask: ")
        key = msg[:4]
        content = msg[4:].strip()
        received_data = 0
        s_sock.sendto(msg.encode(), addr)
        if key == "chat":
            print(f"Server => {s_sock.recvfrom(1024)[0].decode()}")
            continue
        elif key == "file":  # 받기
            data, addr = s_sock.recvfrom(1024)
            datasize = int(data.decode())
            print(f"datasize = {datasize}")
            with open('D:/receive/' + content, 'wb') as f:
                while True:
                    data, addr = s_sock.recvfrom(8192)
                    received_data += len(data)
                    f.write(data)
                    s_sock.sendto("ACK".encode(), addr)
                    if datasize <= received_data:
                        print(f"received_data => {received_data}")
                        print("datasize >= received_data")
                        break
                print(content + ' Download completed')
            continue
        elif key == "stop":
            break
        else:
            received_msg, addr = s_sock.recvfrom(1024)
            print(received_msg.decode())
            print("Use chat or file or stop ")

    s_sock.close()
    print("Connection closed")

server()