a=[5,1,3,8,4]
n=5
temp=0
for i in range(0,n):
	for j in range(i+1,n):
		if(a[i]>a[j]):
			temp=a[i]
			a[i]=a[j]
			a[j]=temp
for i in range(0,n):
	print a[i],
