#client
#192.168.235.1

import socket

port = 2800
address = ("localhost", port)

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect(address)

n = s.recv(1024).decode()
# nInt = int(n)
print("당신은 ", n, "번째 접속자입니다.")


# while True:
#     # n = s.recv(1024)
#     nInt = int(n)
#     print("당신은 ", nInt, "번째 접속자입니다.")
#
#     msg = input("Message to send : ")
#     s.send(msg.encode())
#     if not msg:
#         print("end")
#         break
