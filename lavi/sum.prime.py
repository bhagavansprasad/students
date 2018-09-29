n=10
i=2
j=2
sum=0
for i in range(2,n+1):
	for j in range(2,i+1):
		if(i%j==0):
			break
	if(i==j):
		print i
		sum=sum+i
print sum
