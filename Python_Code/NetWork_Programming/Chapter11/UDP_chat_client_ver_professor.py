import socket
bufferSize = 1024
port = 2800

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
# sock.settimeout(0.5)
ip_addr = input('Server IP Address: ')
if ip_addr == '':
    ip_addr = 'localhost'
addr = (ip_addr, port)

while True:
    msg = input("sendMsg => ")
    sock.sendto(msg.encode(), addr)

    try:
        data, addr = sock.recvfrom(bufferSize)
    except:
        continue
    else:
        # print("-> ", end = '')
        print("receivedMsg ", end = '')
        print(data.decode())

    # print("-> ", end = '')
    # print("inputMsg => ", end = '')
