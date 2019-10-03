a = 298
x = 0

x = x + a % 10 #8
a = int(a/10)  #29

x = x + a % 10 #17
a = int(a/10)  #2

x = x + a % 10 #19
a = int(a/10)  #0

print (x)
print (a)

# + - * / %
# > < != >= <= ==

a = 10
b = 20

if (a == b):
    print("Both are equall")

if (a > b):
    print("A is big")
else:
    print("B is big")

if (a < b):
    print("A is small")
else:
    print("B is small")

if (a != b):
    print("A is small")
else:
    print("B is small")
