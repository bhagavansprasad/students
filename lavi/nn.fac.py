i=1
num = 0
sum = 0
def factorial(n):
	f=1
	for i in range(1,n+1):
		f=f*i
	return f
for i in range (1, 5):
	num = factorial(i+1)/factorial(i)		
	sum = sum + num
print sum
