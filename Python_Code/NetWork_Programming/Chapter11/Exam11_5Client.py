import socket
BUFFSIZE = 1024
port = 2500

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
msg = "Hello UDP server"
sock.sendto(msg.encode(), ('localhost', port))

while True:
    numIn = input("숫자,진수(10진수=>d, 2진수=>b) 입력: ").split(',')
    if numIn == "finish":
        sock.sendto(numIn[0].encode(), ('localhost', port))
        break
    num = numIn[0]
    numShape = numIn[1]
    if numShape == 'd':
        sock.sendto(f"{num},{numShape}".encode(), ('localhost', port))
    elif numShape == 'b':
        sock.sendto(f"0b{num},{numShape}".encode(), ('localhost', port))
    else:
        print("Wrong input")
        continue
    data, addr = sock.recvfrom(BUFFSIZE)
    print(f"Server => ({num}, {numShape}) => {data.decode()}")

    # print("Server says:", data.decode())

