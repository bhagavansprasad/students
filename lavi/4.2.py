a= [1,2,3,2,1]
n=5
for i in range(0,n):
	for j in range(i+1,n):
		if(a[i]==a[j]):
			for k in range(j+1,n):
				a[j]=a[k]
			n-=1
for i in range(n):
	print a[i],
