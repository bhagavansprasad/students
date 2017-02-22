n = 25
m = 12
o = 17

i = 2
flag = 1
while (i < m):
    if (m % i == 0):
        flag = 0
        break
    i += 1
if (flag ==  1):
    print "Number ", m, "is a PRIME"
else:
    print "Number ", m, "is a NOT PRIME"


i = 2
flag = 1
while (i < n):
    if (n % i == 0):
        flag = 0
        break
    i += 1
if (flag ==  1):
    print "Number ", n, "is a PRIME"
else:
    print "Number ", n, "is a NOT PRIME"

i = 2
flag = 1
while (i < o):
    if (o % i == 0):
        flag = 0
        break
    i += 1

if (flag ==  1):
    print "Number ", o, "is a PRIME"
else:
    print "Number ", o, "is a NOT PRIME"


