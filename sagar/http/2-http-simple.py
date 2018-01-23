#!/usr/bin/env python
import httplib
import urlparse


def my_http_request(url):
    """Get the Content-Type of the given url, using a HEAD request"""
    scheme, server, path, query, fragment = urlparse.urlsplit(url)
    print "scheme :", scheme
    print "server :", server
    print "path   :", path
    print "query  :", query
    print "fragment :", fragment

    if scheme == 'http':
        ConnClass = httplib.HTTPConnection
    elif scheme == 'https':
        ConnClass = httplib.HTTPSConnection
    else:
        print 'Invalid connection type :', scheme
        return ' '

    conn = ConnClass(server)
    try:
        conn.request('GET', path, headers={'Host': server})
        response = conn.getresponse()
        print response.status, response.reason

        return response.getheader('Content-Type') or ''
    finally:
        conn.close()


url = "http://www.python.org/index.html"
response = my_http_request(url)
data = response.read()
print data
message = response.msg
print message

if response.status != 200:
    print "Error response", response.status, response.reason



''' 
conn = httplib.HTTPConnection("www.python.org")
conn.request("GET", "/index.html")
response = conn.getresponse()
print response.status, response.reason
data = response.read()
print data

message = response.msg
#print "response.url :", response.url
print "getheaders :", response.getheaders
print "msg        :", response.msg
print "Location   :", response.msg['Location']
print "Connection :",  message['Connection']

scheme, netloc, path, query, fragment = urlparse.urlsplit(response.msg['Location'])
print "scheme :", scheme
print "netloc :", netloc
print "path   :", path
print "query  :", query
print "fragment :", fragment

conn.close()

print "================="
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
''' 

