import socket

port = 2900
bufferSize = 1024
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
# sock.settimeout(0.5)
sock.bind(('', port))

print("Waiting for client")
while True:
    # print("<- ", end= '')
    data, addr = sock.recvfrom(bufferSize)
    print("receivedMsg => ", end= '')
    print(data.decode())

    resp = input("sendMsg => ")
    sock.sendto(resp.encode(), addr)