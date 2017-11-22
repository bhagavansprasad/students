import sys

for i in range(1,10):
    print(i)

for i in range(1,10):
    print(i),

print ""

for i in range(1,10):
    sys.stdout.softspace=1
    print(i),

'''
for i in range(1,10):
    print(i, end=' ')

print("")

print("hello", end=' ')
sys.stdout.softspace=0
print("world", end=' ')

print("!")

for i in range(1, 6):
    sys.stdout.softspace=0
    print(i, end=' ')
'''
