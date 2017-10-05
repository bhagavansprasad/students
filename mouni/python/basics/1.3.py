a=626 
n=a
c=0
c=(c*10)+(a%10)
a=a/10
c=(c*10)+(a%10)
a=a/10
c=(c*10)+(a%10)
a=a/10
if (n==c):
	print 'palindrome'
else:
	print 'not palindrome'
