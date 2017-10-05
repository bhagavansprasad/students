a=[[1,2], [3,4]]
b=[[5,6], [7,8]]
c=[4*[0] for i in range(3)]
n=2
for i in range(0,n):
	for j in range(0,n):
		for k in range(0,n):
			c[i][j]=c[i][j]+a[i][k]*b[k][j]
for i in range(0,n):
	for j in range(0,n):
		print c[i][j],
