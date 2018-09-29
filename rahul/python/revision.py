'''
i = 5
a = 0 
b = 1
c = 0
while (i >= 0):
	c= a+b
	a = b
	b = c
	i = i - 1
	print c
'''
x = 1
n = 4
i = 0
if (i<=n):
	i = i +1
	print i
else:
	x = i -2
	print x
while (x<=n):
		x = x-1
while (x!= 0):
			print x




exit (1)
'''
num = 1
for i in range(0,5):
	for j in range(5,i,-1):
		print num,
		num = num + 1
	print
	num = 1
'''


'''
num = 1
for i in range(0,5):
	num = 1
	for j in range(0,i+1):
		print num,  
		num = num +1
	print
'''







tuple1 = ("python" , "abcde", 1234,4589,7894)
tuple2 = (1,2,3,4,5)
tuple3 = tuple1 + tuple2
print tuple3
print (tuple3 * 3)
print(tuple1[1:6])
print(tuple2[1:])

print ""

email = "rahulrohit1989@gmail.com"
print email.split("@")
username = email.split('@')[0]	
print username
dname = email.split('@')[1]
print dname
print ""

username,dname = email.split('@')

print username
print dname

str = "Line1-a b c d e f\nLine2-a b c\n\nLine4-a b c d";
print str.splitlines()
print str.splitlines(0)
print str.splitlines(1)
print str.splitlines(4)
print str.splitlines(5)
