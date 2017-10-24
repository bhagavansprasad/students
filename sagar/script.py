myfile= open("1log.txt", "rt")
data = myfile.read().replace("\n",'')
newdata="warning"
print("Warning:",data.count(newdata))
a=data.count(newdata)
myfile.close()

myfile= open("2log.txt", "rt")
data = myfile.read().replace("\n",'')
newdata="warning"
print("Warning:",data.count(newdata))
b=data.count(newdata)
myfile.close()

if(b<=a):
	print("promoted no of warnings in previous build is",a)
	print("no of warnings in previous build is",b)
else:
	print("not promoted no of warnings in previous build is",a)
	print("no of warnings in previous build is",b)




