#!/usr/bin/env python
import httplib2
import urlparse

conn = httplib2.Http("www.python.org")
conn.request("GET", "/index.html")
response = conn.getresponse()
print (response.status, response.reason)
data = response.read()
print (data)

message = response.msg
#print ("response.url :", response.url)
print("getheaders :", response.getheaders)
print ("msg        :", response.msg)
print ("Location   :", response.msg['Location'])
print ("Connection :", message['Connection'])

scheme, netloc, path, query, fragment = urlparse.urlsplit(response.msg['Location'])
print ("scheme :", scheme)
print ("netloc :", netloc)
print ("path   :", path)
print ("query  :", query)
print ("fragment :", fragment)

conn.close()
exit(1)
print ("=================")

if scheme == 'http':
     ConnClass = httplib.HTTPConnection
elif scheme == 'https':
     ConnClass = httplib.HTTPSConnection
else:
     ## FIXME: some warning or something?
     ## assertion error?
     #return ''
     print 'scheme error'
     exit(1)
if query:
     path += '?' + query

conn = ConnClass(netloc)

try:
     conn.request('HEAD', path, headers={'Host': netloc})
     resp = conn.getresponse()
     print response.status, response.reason
     print "msg        :", response.msg
     if resp.status != 200:
         ## FIXME: doesn't handle redirects
         #return ''
         print "error in status"
         exit(1)
     print resp.getheader('Content-Type') or ''
finally:
     conn.close()



import httplib
conn = httplib.HTTPSConnection('192.168.1.254',8080)
conn.set_tunnel("ccc.de")
conn.request("GET", "/")
response = conn.getresponse()
print response.status, response.reason
data = response.read()
print data


