sum =0
def fact(n):
	f=1
	for i in range(1,n + 1):
          f=f*i
	return f

n=5
i=1
for i in range(1,n + 1):
	print fact(i+1)/fact(i)
	sum=sum+fact(i+1)/fact(i)
print sum
