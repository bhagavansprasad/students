import sys
import csv

with open("fixed-ip-list.csv") as fd:
    data=[list(line) for line in csv.reader(fd)]
    l1=len(data)
    l=len(data[0]) 
    z=0
    for i in range(0,l1):
	for j in range(i+1,l1):
		if(data[i]==data[j]):
			i=i+1
		else:
#			print("not matched")   
			fd=open("dhcpd.conf","r")
			b=fd.read()
			a=0
			z=0
			a=(b.rfind('fixed-address'))    #finding ip address 
			z=b.find(';',a)				#finding semicolon in that line
			v=[]
			for i in range(z-1,a,-1):		#range from reverse in the same line
			    if(ord(b[i])==ord('.')):		# when it reaches (.) dot it breaks
			        break
			    else:
			        v+=b[i]  			#else 
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
			#print("host",sys.argv[1],"{")   for command line arguments
			print("host %s {" % data[i][0])
			#print('        hardware ethernet %s;' %(sys.argv[2])) for command line arguments
			print('        hardware ethernet %s;' % data[i][1])
			print('        fixed-address 192.168.1.%s;' %(ip))
			print('        option routers 192.168.1.1;')
			print('}')
			print(" ")
		
			fd.close()			

	
#name=row[0]
#mac=row[1]
#print(name)
#print(mac)
'''                                                                                                            
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
	#print("host",sys.argv[1],"{")   for command line arguments
	print("host %s {" % name)
	#print('        hardware ethernet %s;' %(sys.argv[2])) for command line arguments
	print('        hardware ethernet %s;' % mac)
	print('        fixed-address 192.168.1.%s;' %(ip))
	print('        option routers 192.168.1.1;')
	print('}')
	print(" ")
	
	fd.close()
'''									
