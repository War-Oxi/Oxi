import socket
import time

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
address = ('', 3300)
sock.bind(address)
sock.listen(5)

count = 1
while True:
    client, addr = sock.accept()
    print("Connection requested from", addr)
    client.send(f"현재시각 :{time.ctime(time.time())} "
                f"\n당신은 {count}번째 접속자입니다.".encode())
    client.close()
    count += 1
sock.close()

