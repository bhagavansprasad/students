def is_prime(num):
    i = 2
    flag = 1
    while (i < num):
        if (num % i == 0):
            flag = 0
            break
        i += 1

    if (flag ==  1):
        return 1
    else:
        return 0


n = 25
m = 12
o = 17
t = is_prime(m)
if t ==  1:
    print "Number ", m, "is a PRIME"
else:
    print "Number ", m, "is a NOT PRIME"

t = is_prime(n)
if (t ==  1):
    print "Number ", n, "is a PRIME"
else:
    print "Number ", n, "is a NOT PRIME"

t = is_prime(o)
if (t ==  1):
    print "Number ", o, "is a PRIME"
else:
    print "Number ", o, "is a NOT PRIME"

