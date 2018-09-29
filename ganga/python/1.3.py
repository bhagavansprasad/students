a = 626
c = a
b = 0
while c > 0:
	b = b * 10 + c % 10
	c = c / 10
if a == b:
	print "it is a pallindrome"
else:
	print "not a pallindrome"
