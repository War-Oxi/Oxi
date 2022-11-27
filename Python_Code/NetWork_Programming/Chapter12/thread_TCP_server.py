import socket
import _thread

BUFFSIZE = 1024
host_addr = '127.0.0.1'
port = 2500

def response(key):
    return '서버 응답 메시지'

def write_handler(clientsock, addr):
    msg = input("[Server] Sending message : ")
    clientsock.send(msg.encode())
    print('sent: ' + msg)


def handler(clientsock, addr):
    while True:
        data = clientsock.recv(BUFFSIZE)
        print('data:' + data.decode())
        if not data: break
        _thread.start_new_thread(write_handler, (clientsock, addr))


if __name__ == '__main__':
    ADDR = (host_addr, port)
    serversock = socket.socket()
    serversock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    serversock.bind(ADDR)
    serversock.listen(5)

    while True:
        print('waiting for connection...')
        clientsock, addr = serversock.accept()
        print('...connected from: ', addr)
        _thread.start_new_thread(handler, (clientsock, addr))