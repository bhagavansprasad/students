i=2
n=10
flag=0
for i in range(2,n):
	if(n%i==0):
		flag=1
		break
if(flag==0):
	print "prime"
else:
	print "not prime"
