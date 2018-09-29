import  dumphelp
#print help("modules")
#print help("modules pdb")
#print dir(mylist)

mylist = []
print(dir(mylist))
print(dir(mylist.append))

dumphelp.dump_object_help(mylist)

hobj = mylist
'''
for member in dir(mylist)[13:]:
    if (member.find("__") == -1):
        print help(mylist.member)
        #print help(member)
'''
