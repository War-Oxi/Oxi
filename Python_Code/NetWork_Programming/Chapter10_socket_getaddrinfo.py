import socket

def get_constants(prefix):
    return {
        getattr(socket, n):n
        for n in dir(socket)
        if n.startswith(prefix)
    }

families = get_constants('AF_')
types = get_constants('SOCK_')
protocols = get_constants('IPPROTO_')

for response in socket.getaddrinfo('www.naver.com', 'http'):
    # family, socktype, proto, canonname, sockaddr = response
    #
    # print('Family    :',families[family])
    # print('Type      :',types[socktype])
    # print('Protocal  :',protocols[proto])
    # print('Canonical name:', canonname)
    # print('Socket address:', sockaddr)
    # print()

    print('Family    :', response[0])
    print('Type      :', response[1])
    print('Protocal  :', response[2])
    print('Canonical name:', response[3])
    print('Socket address:', response[4])
    # print(response[5])
    print()
