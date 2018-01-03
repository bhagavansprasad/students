n=5
a=[[0 for i in range(n)]for j in range(n)]
i=0
j=n/2
for k in range(1,n*n+1):
	a[i][j]=k
	i=i-1
	j=j+1
	if(k%n==0):
		i=i+2
		j=j-1
	if(j==n):
		j=j-n
	if(i<0):
		i=i+n
print a,
