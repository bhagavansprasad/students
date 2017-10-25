import sys

print (sys.argv)
print (sys.argv[0])
print (sys.argv[1])
print (sys.argv[2])

print (len(sys.argv))

for args in sys.argv:
    print (args)


#ofd = open(sys.argv[1], "r")
#nfd = open(sys.argv[2], "r")


#fd1 = open("sys.argv[1]", "rt")
fd1= open(sys.argv[1], "rt")
data = fd1.read().replace("\n", '')
newdata="warning:"

old_warn_count = data.count(newdata)
fd1.close()

#fd2 = open("argv[2]", "rt")
fd2= open(sys.argv[2], "rt")
data = fd2.read().replace("\n",'')
newdata="warning:"

new_warn_count=data.count(newdata)
fd2.close()

if(new_warn_count <= old_warn_count):
	print("*** Build promoted ***")
else:
	print("*** Build NOT promoted ***")

print("   Old warning count :%d" % old_warn_count)
print("   New warning count :%d" % new_warn_count)



