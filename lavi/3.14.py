n=5
for i in range(5,0,-1):
	for j in range(1,n+1):
		if(j<=i):
			print j,
		else:
			print " ",
	for k in range(4,0,-1):
		if(k<=i):
			print k,
		else:
			print  " ",
	print " "
