import socket
import sys, os
import xmltodict,json

try:
	s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
 	print "socket successfully created"
except socket.error as err:
	print "socket creation failed with error %s" %(err)

port = 8000

s.connect(('192.168.1.7', port))

s.send('GET /search?c=main&q=narendra+modi&format=xml&quick=1&hasmime=1 HTTP/1.1  Host: 192.168.1.7:8000  User-Agent: Mozilla/5.0 (X11; Ubuntu; Linux i686; rv:20.0) Gecko/20100101 Firefox/20.0  Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8 Accept-Language: en-US,en;q=0.5  Accept-Encoding: gzip, deflate  Referer: http://127.0.0.1:8000/search?c=main&q=nagesh  Connection: keep-alive If-Modified-Since: Thu, 05 Jun 2014 06:18:10 GMT\r\n\r\n')

data = ''
data1 = ''
while True:
   	data = s.recv(1000)
	data1 = data1+data
    	if not data:break

xmldata = (data1[268:])

result = xmltodict.parse(xmldata)

jdata = json.dumps(result)

jsonObj = json.loads(jdata)

print jsonObj['response']['result'][0]['spidered']
print jsonObj['response']['result'][0]['sum']
print jsonObj['response']['result'][0]['site']
print jsonObj['response']['result'][0]['url']

s.close()



