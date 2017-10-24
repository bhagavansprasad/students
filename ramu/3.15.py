for i in range(1,6):
	for j in range(1,6):
		if(j<=i):
			print j,
		else:
			print " ",
	for k in range(4,0,-1):
		if(k<=i):
			print k,
		else:
			print " ", 
	print "\n"
