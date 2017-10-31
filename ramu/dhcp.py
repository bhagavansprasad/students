import re
a=open("output-conf.txt","r+")
b= a.read()
print (b)
v=open("input-conf.txt","r")
s =v.read()
print (s)
for line in a:
	if (('ethernet ' in line) and ('address ' in line)):
		locat = re.search( 'ethernet',line)
		print(locat)
with open("write.txt","w") as w:
		w.writelines(b)
        
