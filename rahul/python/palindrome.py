a= 121
t = a
x= 0
x = a%10 + x*10
a = a/10
x = a%10 + x*10
a = a/10
x = a%10 + x*10
a = a/10
if (t==x):
	print ("palindrome no")
else:
	print ("not palindrome ")
