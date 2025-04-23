a = [10, 20, 30, 40, 50]

print(a[0])
print(a[4])
a[1] = a[0] + a[2]
print(a[0])
print(a[1])
print(a[2])
print(a[3])
print(a[4])

for i in range(0, 5):
    print(a[i])
    
# Initial values
a = [4, 6, 8, 3, 6, 9, 2]

n = 7
# i j
# 0 1
# 0 2    # 1 2   #       
# 0 3    # 1 3   # 2 3   
# 0 4    # 1 4   # 2 4   # 3 4   
# 0 5    # 1 5   # 2 5   # 3 5   # 4 5  
# 0 6    # 1 6   # 2 6   # 3 6   # 4 6  # 5 6

if(a[i] == a[j]):
    a[j] = 0 

# .....

# After replacing duplicates with '0'
a = [4, 6, 8, 3, 0, 9, 2]

# After removing duplicates
a = [4, 6, 8, 3, 9, 2]
