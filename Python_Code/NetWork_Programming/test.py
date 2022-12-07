import ipaddress

addr4 = ipaddress.ip_address('192.0.2.255')

print(addr4)

print(addr4 in ipaddress.ip_network('192.0.2.0/24'))
