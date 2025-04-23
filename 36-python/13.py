a = 426
t = a
r = 0

print("Before reversing...")
print(f"a :{a}")
print(f"r :{r}")

r = r * 10 + a%10
a = a // 10

r = r * 10 + a%10
a = a // 10

r = r * 10 + a%10
a = a // 10

print("After reversing...")
print(f"a :{a}")
print(f"t :{t}")
print(f"r :{r}")

# Compare a and r, if they are same
# print a is palindrome
# otherwise not a palindrome

if(t == r):
    print(f"{t} is a PALINDROME")
else:
    print(f"{t} is NOT a PALINDROME")