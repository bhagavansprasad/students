def prime(n):
	i = 0

	for i in range (2, n):

		if(n%i==0):
			break

	if(i==n-1):
		return(1)
	else:
		return(0)


n = 10
i = 0
for i in range(0, n+1):
	if (prime(i)==1):
		print (i)
