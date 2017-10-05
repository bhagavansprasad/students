a=[1, 1, 2, 2, 1, 2, 1, 1, 2, 2, 3, 2, 3, 4, 4, 5 ,6]
i=1
n=15
for i in range(0,n):
	for j in range(i+1,n):
		if(a[i]==a[j]):
		      a[j] = 0
print a,
