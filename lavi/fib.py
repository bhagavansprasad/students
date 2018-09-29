p=0
c=1
n=10
s=0
i=1
while(i<=10):
	a=p+c
	p=c
	c=a
	print a
	s=s+a
	i+=1
print("sum of the series is : %d" % (s))
