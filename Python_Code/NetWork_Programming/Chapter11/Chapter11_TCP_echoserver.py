import socket

port = 2500
BUFSIZE = 1024

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.bind(('', port))
sock.listen(5)
print("Waiting for clients...")

c_sock, (r_host, r_port) = sock.accept()
print('connected by', r_host, r_port)
while True:
    try:
        data = c_sock.recv(BUFSIZE)
        if not data:
            c_sock.close()
            print('연결이 종료되었습니다1')
            break
    except:
        print("연결이 종료되었습니다2")
        c_sock.close()
        break
    else:
        print(data.decode())

    try:
        c_sock.send(data)
    except:
        print("메세지를 전송하지 못했습니다. \n연결을 종료합니다.")
        c_sock.close()
        break