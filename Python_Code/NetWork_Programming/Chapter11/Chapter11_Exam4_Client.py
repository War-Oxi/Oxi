import socket

c_sock = socket.create_connection(('localhost', 3000))
print("Connect Complete")
message = "I want connect (Server) "

# print(f'sending {message} ')
c_sock.send(message.encode())

while True:
    data = input("학생의 이름을 입력하세요 => ")
    c_sock.send(data.encode())
    if data == "exit":
        break
    receivedMsg = c_sock.recv(1024).decode()
    print(f"{data}학생의 학번 =>{receivedMsg}")