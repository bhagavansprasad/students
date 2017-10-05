a = 256
b = 0
j = 0
for i in range(31, -1, -1):
	j = 1 << i
	b = a & j
	
	if( b == 0):
		print "0",
	else:
		print "1",
