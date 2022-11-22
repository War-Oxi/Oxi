

# server
import socket
import sys

# BUFSIZE = 1024

port = 3400
s_sock = socket.socket()
host = ""
s_sock.bind((host, port))
s_sock.listen(1)

print('Waiting for connection....')

c_sock, addr = s_sock.accept()
print('Connected from', addr)
msg = c_sock.recv(1024)
print(msg.decode())


# while True:
received_option = c_sock.recv(1024).decode()
print("received option => " + received_option)
# if received_option == 3:
#     break
# elif
#     msg = c_sock.recv(1024).encode()
#     print(f"Sending '{msg}'")
#     c_sock.send(msg)
if received_option == "1":
    recv_msg = c_sock.recv(1024).decode()
    print("받은 메시지 => " + recv_msg)
    c_sock.send("message received".encode())
elif received_option == "2":
    ## 파일 이름을 받는 것을 구현
    filename = c_sock.recv(1024).decode()
    print(f"Sending '{filename}'")
    fn = filename.split('/')

    c_sock.sendall(fn[-1].encode())

    with open(filename, 'rb') as f:
        c_sock.sendfile(f, 0)

    print('Sending complete')
    # complete_msg = c_sock.recv(1024).encode()
    # print(complete_msg)
    # print(c_sock.recv(1024).encode())
    # while True:
    #     if complete_msg == "Receiver download complete":
    #         break
    # break
print("Disconnect")
c_sock.close()