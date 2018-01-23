import sys

n = 10

n = int(sys.argv[1])

for i in range (1, n+1):
	print (i), 

print ""
print ("argv       :", sys.argv)
print ("argv[0]    :", sys.argv[0])
print ("args count :", len(sys.argv))

for i, args in enumerate(sys.argv):
    print ("argv[%d]: %s" % (i, args))

fd = open(sys.argv[2], "r")

list_of_servers = fd.readlines()

print list_of_servers 

for server in list_of_servers:
    print server
exit(1)

