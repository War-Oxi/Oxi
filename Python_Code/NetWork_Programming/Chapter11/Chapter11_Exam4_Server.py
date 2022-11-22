import socket

table = {'홍길동': 20150001, '심순애': 20150002, '박문수': 20150003}

s_sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
address = ("", 3000)
s_sock.bind(address)
s_sock.listen(1)

print("Waiting For Connection")

c_sock, c_addr = s_sock.accept()
print("Connect form ", c_addr)
print(f"{c_sock.recv(1024).decode()}")

while True:
    data = c_sock.recv(1024).decode()
    if data == "exit":
        break
    try:
        numOfStudent = table[data]
    except:
        c_sock.send(f"{data}라는 학생은 없습니다. "
                    f"다시 입력해 주세요".encode())
    else:
        c_sock.send(str(numOfStudent).encode())

