import sys
import csv

#taking the input fron csv file

with open('fixed-ip-list.csv') as fd:
	data=[list(line) for line in csv.reader(fd)]
	for row in data:
		sysname=row[0]
		macadd=row[1]
		
#print(sysname)
#print(macadd)
fd.close()
exit(1)

#finding the last ip address from main file

fd=open("dhcpd.conf","r")
b=fd.read()
a=0
z=0
a=(b.rfind('fixed-address'))
z=b.find(';',a)
v=[]
for i in range(z-1,a,-1):
    if(ord(b[i])==ord('.')):
        break
    else:
        v+=b[i]  
x=v[::-1]
ip1="".join(x)
ip=int(ip1)
ip=ip+1
if(ip>254):
    ip=3
str(ip)
fd.close()

# appending to the file
fd=open("dhcpd.conf","a")
sys.stdout=fd
print("host",sysname,"{")
print('        hardware ethernet %s;' % macadd)
print('        fixed-address 192.168.1.%s;'	 %(ip))
print('        option routers 192.168.1.1;')
print('}')
print(" ")

fd.close()

