__author__ = 'pitochka'


import socket


__recive_msg__ = 'Hello, client (MyServer 1.1)\n'

sock = socket.socket()
sock.bind(('', 22000))
sock.listen(1)

while True:
    conn, addr = sock.accept()
    print 'connected:', addr
    data = conn.recv(1024)
    if not data:
        break
    conn.send(__recive_msg__)

conn.close()