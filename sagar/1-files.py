import time

'''
fd = open("t.txt", "rt")
data = fd.read(5)
print("data :", data)

fd.close()
''


fd = open("t.txt", "r")

data = fd.read(10)
print("1: data :", data)

data = fd.read(10)
print("2 :data :", data)

fd.close()


fd = open("t.txt", "r")
i = 0
while(True):
    data = fd.read(10)
    print("%d : %s" % (i, data))
    print(len(data))
    if (len(data) < 10):
        break
    i  = i + 1
    #time.sleep(1)

fd.close()
exit(0);




fd = open("t.txt", "r")
i = 0
while(True):
    data = fd.readline()
    print("%d : len :%d, %s" % (i, len(data), data))
    if (len(data) <= 0):
        break
    i  = i + 1

fd.close()
'''

'''
fd = open("t.txt", "r")
data = fd.readlines()
print("len :%d, %s" % (len(data), data))

i = 1
for line in data:
    print("%d. %s" % (i, line))
    i = i + 1

fd.close()
'''

'''
fd = open("t.txt", "r")
#print "fd :", fd
print(("file position ", fd.tell()))

data = fd.read(10)
print(("data :", data))
print(("file position ", fd.tell()))

print("")

data = fd.read(10)
print(data)
print(("file position ", fd.tell()))

fd.seek(40)
print(("file position ", fd.tell()))

data = fd.read(10)
print(data)
print(("file position ", fd.tell()))

fd.seek(0, 0)
print(("file position ", fd.tell()))

fd.seek(10, 0)
print(("file position ", fd.tell()))

fd.seek(20, 1)
print(("file position ", fd.tell()))

fd.seek(-10, 2)
print(("file position ", fd.tell()))

fd.seek(0, 2)
print(("file position ", fd.tell()))

fd.seek(30, 0)
print(("file position ", fd.tell()))

fd.seek(-10, 1)
print(("file position ", fd.tell()))

print(("Name of the file  :", fd.name))
print(("Closed or not     :", fd.closed))
print(("Opening mode      :", fd.mode))
print(("Softspace flag    :", fd.softspace))

fd.close()
exit(1)
'''
