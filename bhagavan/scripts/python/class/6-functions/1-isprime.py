n = 25
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


