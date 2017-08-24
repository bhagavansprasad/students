n=5
i = 0
j = n / 2
a=[[0 for i in range(n)] for j in range(n)]
for k in range(1,n*n + 1):
	a[i][j]=k
	i=i-1
	j=j+1
	if(k%n==0):
		i=i+2
		j=j-1
	elif(j==n):
		j=j-n	
	elif(i<0):
		i=i+n
for i in range(0,n):
	for j in range(0,n):
		print a[i][j],
	print '\n'

