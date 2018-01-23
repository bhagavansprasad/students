fd=open("dhcpd.conf","r")
b=fd.read()   									#Read the Dhcpd 

print(type(b))

str="fixed-address"
l=b.rfind(str) 								    # l=last occurance of string                 
print(l)
semi=b.find(';',l)								#finding the ; in the line
#print(read)
print(semi)
print(b[222])
print(b[semi])
n=0
for i in range(semi,n,-1):
	if(i=='.'):
		break
	print(i)

fd.close()	

