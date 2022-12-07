import socket

host = 'www.ulsan.ac.kr'

hostIpAddress = socket.gethostbyname(host)
print(f"{host} ipaddress => {hostIpAddress}")

print(socket.gethostbyaddr('203.249.39.46'))