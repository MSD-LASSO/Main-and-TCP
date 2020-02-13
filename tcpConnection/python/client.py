#!/usr/bin/env python

import socket

SERVER_IP = "129.21.43.122"
PORT = 5005
BUFFER_SIZE = 1024
MSG_STR = "1234"
MESSAGE = bytes(MSG_STR, 'utf-8')

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# TODO uncomment once running on 2 computers
#s.bind(('', PORT))
s.connect((SERVER_IP, PORT))
s.sendall(MESSAGE)
data = s.recv(BUFFER_SIZE).decode()
s.close()

print("received data:", data)
