"""
range(5)         # 0, 1, 2, 3, 4
range(10)        # 0, 1, 2, 3, 4....9
range(0, 10)     # 0, 1, 2, 3, 4....9
range(1, 10)     # 1, 2, 3, 4....9
range(1, 100)    # 1, 2, 3, 4....99
range(1, 100, 1) # 1, 2, 3, 4....99
range(1, 10, 2)  # 1, 3, 5 7 9
range(1, 10, 3)  # 1, 4, 7
range(10, 1, -1) # 10 9 8 7 6 5 4 3 2
range(10, 1, -2) # 10 8 6 4 2
range(-5, 3, 1)  # -5 -4 -3 -2 -1 0 1 2 
range(5, 5, 1)   # 
range(5, 6, 1)   # 
"""

"""
         #[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
for i in range(10):
    print (i)

print ()

for i in range(1, 10):
    print (i)

print ()

for i in range(1, 10):
    print (i*10)

n = 7
for i in range(1, n):
    print (i)

print ("=====")
i = 1
n = 7
while (True):
    print (i)
    i = i + 1
    if (i == n):
        break

print ("=====")
i = 1
n = 7
while (i <= n):
    print (i)
    i = i + 1

print ("=====")
i = 1
n = 7
while (i < n):
    print (i)
    i = i + 1

"""

i = 1
n = 10
while( i <= n):
    print (i)
    if (i % 5 == 0):
        i += 4
    i = i + 1

print (i)