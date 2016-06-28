__author__ = 'pitochka'

import socket

sock = socket.socket()
sock.connect(('localhost', 22000))
sock.send('hello, world!')

data = sock.recv(1024)
sock.close()

print data