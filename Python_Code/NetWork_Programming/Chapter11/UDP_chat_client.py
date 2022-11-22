import socket
bufferSize = 1024
port = 2800

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
ip_addr = input('Server IP Address: ')
if ip_addr == '':
    ip_addr = 'localhost'
addr = (ip_addr, port)

while True:
    msg = input("sendMsg => ")
    sock.sendto(msg.encode(), addr)
    # print("-> ", end = '')
    print("inputMsg => ", end = '')
    data, addr = sock.recvfrom(bufferSize)
    print(data.decode())