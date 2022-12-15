import socket
port = 2500
BUFFER = 1024

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind(('', port))
print('수신 대기 중')

while True:
    data, addr = sock.recvfrom(BUFFER)
    print("Received message: ", data.decode())
    print(addr)
    sock.sendto(data, addr)