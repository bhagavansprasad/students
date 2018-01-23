n=int(input())
f1=0
f2=1
c=0
d=0
e=0
for i in range(1,n+1):
		f1=f2
		f2=c
		c=f1+f2
		print(c)
		e=c
		d=d+e
print("\n")		
print(d)


