import sys

print (sys.argv)
print (sys.argv[0])
print (sys.argv[1])
print (sys.argv[2])

print (len(sys.argv))

for args in sys.argv:
    print (args)


ofd = open(sys.argv[1], "r")
nfd = open(sys.argv[2], "r")

