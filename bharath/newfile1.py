from a2to3 import  python_port2x_to_3x
def fileproject(nfiles):
	with open("f0.py","r") as f1:
		with open("f2.py","r") as f2:
			with open("f3.py","w") as f3:
				nfiles = ["f0.py","f2.py"]
				of = ["f3.py"]
	for n in nfiles[0]:
		n.readlines()
		for i in nfiles[1]:
			for m in of:
				if n != i:
					f3.writelines("%s"%n)
				else:
					print(i)
#d=fileproject(n)
#print(d)

	i = 1
	for nstr in f1:
		(result, pos) = python_port2x_to_3x(nstr[1])
		if (result == True):
			print ("-->%d:%s, pos :%d" % (i,  nstr[1], pos))
			ts = nstr[1][:pos] + '(' + nstr[1][pos:] + ')'
			print ("     %s" % (ts))
		i = i + 1
fileproject("f0.py")

f1.close()
f2.close()
f3.close()


