import MyTCPServer as ms

server = ms.TCPServer(2500)
print("Waiting for connection")
while True:
    if not server.connected:
        server.accept()
    else:
        msg = server.receive()
        # 연결이 되어 있지 않으면 None이 반환
        if msg:
            print('수신메시지: ', msg)
            server.send(msg)
        else:
            print("Disconnected")
            break
server.disconnect()