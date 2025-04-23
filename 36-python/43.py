a = [2, 5, 3, 9, 5] # 1x7
b = [1, 3, 7, 1, 8] # 1x7

# 3x3

c = a + b
c = a - b
c = a * b

i = j = 0
a = [
   # 0  1  2
    [2, 5, 3], # 0
    [1, 4, 9], # 1
    [6, 0, 4], # 2   
    [6, 0, 4], # 4
]
print(a[0][0])
print(a[0][1])
print(a[0][2])
# ....
print(a[2][1])
# i j
# 0 0
# 0 1
# 0 2

# 1 0
# 1 1
# 1 2

# 2 0
# 2 1
# 2 2
print(a[i][j])


a = [
    [2, 5, 3],
    [1, 4, 9],
    [6, 0, 4],    
]

b = [
    [5, 8, 9],
    [1, 1, 2],
    [8, 6, 4],    
]

c = [
    [0, 0, 0],
    [0, 0, 0],
    [0, 0, 0],    
]

print("Before addition....")
print(f"a...")
for row in a:
    print(f"{row}")

print(f"b...")
for row in b:
    print(f"{row}")

print(f"c...")
for row in c:
    print(f"{row}")
    
# logic
c[0][0] = a[0][0] + b[0][0]
c[0][1] = a[0][1] + b[0][1]
c[i][j] = a[i][j] + b[i][j]
c[i][j] = a[i][j] - b[i][j]
# c[i][j] = a[i][j] * b[i][j]


print()
print("After addition....")
print(f"a...")
for row in a:
    print(f"{row}")

print(f"b...")
for row in b:
    print(f"{row}")

print(f"c...")
for row in c:
    print(f"{row}")
    
