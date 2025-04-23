n = 5
# 1 * 2 * 3 * 4 * 5 = 120
p = 1

for i in range(1, n+1):
    print(i)
    p = p * i
    
print(p)

# 1  1
# i  p
# 1  1
# 2  2
# 3  6
# 4 24
# 5 120

# --------------

n = 5
# 5 * 4 * 3 * 2 * 1 = 120
p = 1

for i in range(n, 0):
    p = p * i
    
print(p)

# --------------
a = 10; b = 5; c = 7

p = 1
for i in range(a, 0):
    p = p * i
print(p)

p = 1
for i in range(b, 0):
    p = p * i
print(p)

p = 1
for i in range(c, 0):
    p = p * i
print(p)
# --------------
def myfactorial(x):
    p = 1
    for i in range(x, 0):
        p = p * i
    print(p)

a = 10; b = 5; c = 7
myfactorial(5)
myfactorial(7)
myfactorial(a)
myfactorial(b)
myfactorial(c)

# --------------
def myfactorial(x):
    p = 1
    for i in range(x, 0):
        p = p * i
    return p

a = 10; b = 5; c = 7
t = myfactorial(a)
print(t)

print(myfactorial(b))

t = myfactorial(c)


# ------------------
def myfactorial(x):
    p = 1
    for i in range(x, 0):
        p = p * i
    return p

# 2!/1! +3!/2! +4!/3!+ ....+ (n+1)!/n! ?

n = 5
sum = 0
for i in range(1, n+1):
    # 1 2 3 4 5
    nu = myfactorial(i+1)
    de = myfactorial(i)
    print(nu, de)
    div = nu / de
    print(div)
    sum = sum + div
print(sum)
# ------------------
# 2!/1! +3!/2! +4!/3!+ ....+ (n+1)!/n! ?
n = 5
sum = 0
for i in range(1, n+1):
    sum = sum + (myfactorial(i+1) / myfactorial(i))
    
print(sum)
        
# -------------------

# if n is prime, returns n
# if n is not prime, returns 0
def isprime(n):
    # ....
    pass