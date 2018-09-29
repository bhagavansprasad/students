a=[[1,2], [3,4]]
b=[[5,6], [7,8]]
c=[4*[0] for i in range(2)]
n=2
for i in range(0,n):
	for j in range(0,n):
		c[i][j]=a[i][j]+b[i][j]
for i in range(0,n):
	for j in range(0,n):
		print c[i][j],
