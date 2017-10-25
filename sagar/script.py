fd1 = open("1log.txt", "rt")
data = fd1.read().replace("\n", '')
newdata="warning:"

old_warn_count = data.count(newdata)
fd1.close()

fd2 = open("2log.txt", "rt")
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




