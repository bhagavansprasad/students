f1=open("file.py","r")
f2=open("file1.py","r")
f3=open("file2.py","w")
for line1 in f1:
	for line2 in f2:
		if line1 !=line2:
			f3.write("%s"%line2)
		else:
			print line1
f3.close()
