import socket
port = 2500
BUFFER = 1024

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind(('', port))
print("수신 대기 중")
data, addr = sock.recvfrom(BUFFER)
print("Received message: ", data)

while True:
    data, addr = sock.recvfrom(BUFFER)
    data = data.decode().split(',')
    if data == 'finish':
        sock.sendto('finish'.encode(), addr)
        break

    print(data)
    if data[1] == 'd':
        data[0] = str(bin(int(data[0])))
        data[1] = 'b'
    elif data[1] == 'b':
        data[0] = str(int(data[0], 2))
        data[1] = 'd'

    sock.sendto(f"{data[0]}, {data[1]}".encode(), addr)

