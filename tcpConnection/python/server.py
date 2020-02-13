#!/usr/bin/env python

import socket


HOST = "0.0.0.0"
PORT = 5010
BUFFER_SIZE = 20  # Normally 1024, but we want fast response

hostname = socket.gethostname()
IPAddr = socket.gethostbyname(hostname)    
print("Your Computer IP Address is:" + IPAddr)

print("Binding socket...")
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((HOST, PORT))
s.listen(1)

conn, addr = s.accept()
print('Connection address:', str(addr))
while True:
    data = conn.recv(BUFFER_SIZE)
    if not data:
        break
    print("received data:", data.decode())
    conn.send(data)  # echo
conn.close()
