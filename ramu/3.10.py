j = 1
n=5
for i in range(0, n):
	for j in range(0, i):
		print " ",
	for k in range(1, n - i + 1):
		print k,
	print "\n"
