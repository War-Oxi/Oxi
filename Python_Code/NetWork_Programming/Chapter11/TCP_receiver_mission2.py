#server
import socket

s_sock = socket.socket()
host = "localhost"
port = 3400

s_sock.connect((host, port))
s_sock.send("OK".encode())

option = input("(1) 메시지 전송 (2) 파일 전송 (3) 파일 종료 \noption => ")
s_sock.send(option.encode())

count = 1
# while option != "3":
    # print(option)
    # print(type(option))
if count != 1:
    option = input("(1) 메시지 전송 (2) 파일 전송 (3) 파일 종료 \noption =>")
    s_sock.send(option.encode())
count += 1
if option == "1":
    msg = input('보낼 메시지 내용 => ')
    s_sock.send(msg.encode())
    received_msg = s_sock.recv(1024)
    print(received_msg)
elif option == "2":
    ## 파일 이름 보내는 것을 구현
    filename = input('File name to receive(c:/test/sample.bin): ')
    s_sock.send(filename.encode())

    fn = s_sock.recv(1024).decode()
    print(fn)
    with open('d:/'+fn, 'wb') as f:
        print('file opened')
        print('receiving file...')
        while True:
            data = s_sock.recv(8192)
            # print(data)
            if not data:
                break
            f.write(data)

    print('Download complete')
    # s_sock.send('Receiver download complete'.encode())
    # break
s_sock.close()
print('Connection closed')