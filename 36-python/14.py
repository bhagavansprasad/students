a = 4265
s = 0

# s = s + (a%10) 
# a = a // 10    

# s = s + (a%10) 
# a = a // 10    

# s = s + (a%10) 
# a = a // 10    


while(True):
    s = s + (a%10) 
    a = a // 10
    if (a == 0):
        break

print("After ....")
print(f"a :{a}")
print(f"s :{s}")



a = 426
s = 0

# s = s + (a%10) 
# a = a // 10    

# s = s + (a%10) 
# a = a // 10    

# s = s + (a%10) 
# a = a // 10    


# Relational
# == != > < >= <= 

# while(True):
# while(a == 0):
# while(a >= 0):
# while(a > 0):
while(a != 0):
    s = s + (a%10) 
    a = a // 10
    print(s)
    # if (a == 0):
    #     break

print("After ....")
print(f"a :{a}")
print(f"s :{s}")


