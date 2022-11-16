#server

from socket import *

port = 2800
n = 0

sock = socket(AF_INET, SOCK_STREAM)
sock.bind(('', port))
sock.listen(5)
print("Wating for clients ....")



while True:
    c_sock, (r_host, r_port) = sock.accept()
    n += 1
    print(f"{n}th user Connected by ", r_host, r_port)
    c_sock.send(f"{n}번째 사용자 접속".encode())
    # n += 1
    # print(n, "번째 사용자 접속")
    # nStr = str(n)
    # c_sock.send(nStr.encode())
    
    # data = c_sock.recv(1024)
    # if not data:
    #     break
    # print("Received message: ", data.decode())

c_sock.close()
