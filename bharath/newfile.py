def fileproject(nfiles):
	f1 = open("f0.py","r")
	f2 = open("f2.py","r")
	f3 = open("f3.py","w")
nfiles = ["f0.py","f2.py"]
of = ["f3.py"]
for n in nfiles[0]:
	for i in nfiles[1]:
		for m in of:
			if n != i:
				m.write("%s"%i)
			else:
				print(i)
#d=fileproject(n)
#print(d)

f1.close()
f2.close()
f3.close()


