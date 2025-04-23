a = 426
s = 0

print(a)
print(s)

# 6 + 2 + 4 = 12
# Extract last degit from 'a' and add to 's' --> 6
# strip last degit from 'a' -> 42

# Extract last degit from 'a' and add to 's' --> 8
# strip last degit from 'a' -> 4

# Extract last degit from 'a' and add to 's' --> 12
# strip last degit from 'a' -> 0

# Extract last degit from 'a' and add to 's' --> 6
s = s + (a%10) # 0 + 6 = 6

# Strip last degit from 'a' -> 42
a = a // 10    # 42

s = s + (a%10) # 6 + 2 = 8
a = a // 10    # 4

s = s + (a%10) # 6 + 2 + 4 = 12
a = a // 10    # 0

print(a)
print(s)
