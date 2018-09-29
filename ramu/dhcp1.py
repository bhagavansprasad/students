import sys 
import csv
with open('fixed-ip-list.csv') as fd:
	data=[list(line) for line in csv.reader(fd)
for row in data:
	name=row
	sysname=name[0]
	macadd=name[1]
fd.close()
		w.write(b)
		for i in w:
			i.replace("santhosh-laptop","santhosh-laptop")
			print(i)
net = '192.168.1.215'
host = []
for x in range(1):
    host.append(str(net)+str(x))
print(host)
'''
net = "192.168.1.214"
host= [net + str(i) for i in range (2)]
print (host)
'''
