tstr = "1 2 3 4 7 8 9 10 13 14 15 16 19 20 21 22 25 26 27 28"
llist = tstr.split()
print (llist)

print ()

for (i, element) in enumerate(llist):
	print ("%3d, " % int(element), end="")
	if ((i+1)%4 == 0):
		print ("],")
		print ("[", end="")
