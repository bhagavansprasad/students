import time
import sys
#fd=open("dhcpd.conf","rw")
#data=fd.read()
#print(data)
#fd.close()
ip="192.168.2.3"
import sys
f = open("test.out", 'w')
sys.stdout = f

#print(sys.argv[2])
print("host_ %s {\nhardware element %s\n fixedaddress %s\n}" %(sys.argv[1],sys.argv[2],ip))

f.close()
