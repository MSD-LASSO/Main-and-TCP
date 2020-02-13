#!/usr/bin/env python

import socket


HOST = "0.0.0.0"
PORT = 5000
BUFFER_SIZE = 20  # Normally 1024, but we want fast response

hostname = socket.gethostname()
IPAddr = socket.gethostbyname(hostname)    
print("Your Computer IP Address is:" + IPAddr)


