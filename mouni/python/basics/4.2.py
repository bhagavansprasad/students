a=[10,20,10,20,30]
n=5
for i in range(0,n):
	for j in range(i+1,n):
		if(a[i]==a[j]):
			for k in range(j+1,n):
				a[j]=a[k]
				j=j+1
			n=n-1
for i in range(0,n):
	print a[i]

