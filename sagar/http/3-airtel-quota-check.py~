#!/usr/bin/env python
import httplib
import urlparse

'''
def get_redirected_url(data):
    sp = data.find('src="http') 
    #print sp
    if ( sp > 0):
        ep = data.find(' ', sp) 
        rurl = data[sp:ep]
        rurl = rurl.lstrip('src="').rstrip('"')
        print rurl
    return rurl
'''

def get_redirected_url(data):
    rurl  = ""
    sp = data.find('src="http') 
    if ( sp > 0):
        return data[sp:data.find(' ', sp)].lstrip('src="').rstrip('"')

    return rurl

def send_http_request(url):
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
         print 'scheme error'
         

    conn = ConnClass(server)
    try:
        conn.request('GET', path, headers={'Host': server})
        response = conn.getresponse()
        ''' 
        print "resp, status :", response.status
        print "resp  reason :", response.reason
        print "msg          :", response.msg
        ''' 
        if response.status != 200:
            print "error in status"

        data = response.read()

        return (response, response.status, data)

    finally:
        conn.close()

url = "http://www.airtel.in/smartbyte-s/page.html"
(response, retcode, data) = send_http_request(url)
print "resp, status :", response.status
print "resp  reason :", response.reason
print "retcode      :", retcode

if (retcode == 200):
    print "msg          :", response.msg
else:
    print "Error in request"
    exit(1)

print "------------"
print data
print "------------"

rurl = get_redirected_url(data)
(response, retcode, data) = send_http_request(rurl)
print "resp, status :", response.status
print "resp  reason :", response.reason
print "retcode      :", retcode

print "============="
print data
print "============="

'''
conn = httplib.HTTPConnection("www.airtel.in")
conn.request("GET", "/smartbyte-/page.html")
response = conn.getresponse()
print response.status, response.reason
data = response.read()
print data

message = response.msg
#print "response.url :", response.url
print "getheaders :", response.getheaders
print "msg        :", response.msg
#print "Location   :", response.msg['Location']
print "Connection :",  message['Connection']

'''
