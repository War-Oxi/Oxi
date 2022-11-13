import socket
a = 1234
print(f"hex(a) => {hex(a)}")
b = socket.htons(a)
print(f"hex(b) =>  {hex(b)}")

c = socket.ntohs(b)
print(f"ntonhs(b) => {hex(c)}")