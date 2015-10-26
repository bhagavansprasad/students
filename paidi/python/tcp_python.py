import socket # for socket
import sys

try:
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    print "Socket successfully created"
except socket.error as err:
    print "socket creation failed with error %s" %(err)

port = 8000

s.connect(('127.0.0.1', port))

s.send('GET /search?c=main&format=json&q=narendra+modi HTTP/1.1  Host: 127.0.0.1:8000  User-Agent: Mozilla/5.0 (X11; Ubuntu; Linux i686; rv:20.0) Gecko/20100101 Firefox/20.0  Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8 Accept-Language: en-US,en;q=0.5  Accept-Encoding: gzip, deflate  Referer: http://127.0.0.1:8000/search?c=main&q=nagesh  Connection: keep-alive If-Modified-Since: Thu, 05 Jun 2014 06:18:10 GMT\r\n\r\n')

print s.recv(4000)
print s.recv(4000)
print s.recv(4000)
print s.recv(4000)

s.close()

