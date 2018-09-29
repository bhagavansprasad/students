N=3
k=N-1
a=[[0 for i in range(N)]for j in range(N)]
i=0
j=N/2
n=1
while( n < N*N+1):
	if(a[i][j] == 0):
		a[i][j] = n
		i=i-1
		j=j+1
		n=n+1
	else:
		i=i+2
		j=j-1 
		n=n+1
		i=i-1
		j=j+1
	if( i < 0):
		i=i+N
	if(j>K):
		j=j+N
print a,
print " ",
