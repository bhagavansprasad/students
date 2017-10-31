a=open("output-conf.txt","r")
b= a.read()
print b
v=open("input-conf.txt","r")
s =v.read()
print s
with open("write.txt","w") as w:
		w.writelines(b)
        
