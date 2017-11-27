test_str = "Aura Networks Bangalore"

print (test_str)


for temp in test_str:
	print(temp),

print("")

print(len(test_str))

i = 0
while (i < len(test_str)):
    print(test_str[i]),
    i += 1

print("")

test_str = "Aura Networks Bangalore"

# String is immutable 
print(test_str[2])

#test_str[2] = 'm'
print(test_str)

#this is possible
test_str = "new test string"
print(test_str)

test_str = "Aura Networks Bangalore"
print("     :", test_str)
print(" 0   :", test_str[0])
print(" 1   :", test_str[1])
print(" -1  :", test_str[-1])
print(" -2  :", test_str[-2])
print(" 1:6 :", test_str[1:6])
print(" 1:23:", test_str[1:23])
print(" 1:30:", test_str[1:30])
print(" 0:30:", test_str[0:30])
print(" ':' :", test_str[:])
print("5:   :", test_str[5:])
print("':-1':", test_str[:-1])
print(test_str[-1:])
print(test_str[::-1])
print(test_str[::])
print(test_str[13:-1])
print(test_str[:13:-1])
print(test_str[5::1])
print(test_str[5::2])
print(test_str[5::3])

name = "Saketh Ram"
age = 14
salary = 1000
height = 5.123

#print "name ", name, "age ", age, 
print("my friend ", name, " age is ", age, "and salary is ", salary, "height is ", height)
print("my friend %s age is %d and salary is %d height is %f" % (name, age, salary, height))

print(name, age)
print(name * 3)
print(age * 3)
print(height * 3)
print(str(height) * 3)

s = "Aurovill"
s = "B" + s[:]
print(s)

s = "B" + s[2:]
print(s)

s = "B" + s[2:5]
print(s)

s = "B" + s[1:5]
print(s)

str = "this is string example. and ..wow!!!";
print("str              :", str)
print("str.capitalize() :", str.capitalize())
print("str              :", str)

str =  str.capitalize()
print("str              :", str)
print("")
#print (help(str.capitalize))

print(dir(str))

a = 10
print(dir(a))

str = "this is string example. and temp...wow!!!";
print("str                   :", str)
sub = "i";

print("str.len()             :", len(str))
print("str.count(sub)        :", str.count(sub))
print("str.count(sub, 4)     :", str.count(sub, 4))
print("str.count(sub, 4, 10) :", str.count(sub, 4, 10))
print("str.count(sub, 4, 40) :", str.count(sub, 4, 40))

print("")

sub = "wow";
print("str.count(sub)        :", str.count(sub))

sub = " ";
print("str.count(sub)        :", str.count(sub))

i = 0
str = "this is string example....wow!!!";
print("str                   :", str)
suffix = "wow!!!";
prefix = "This";

print("1. ", str.endswith(suffix))
print("2. ", str.endswith(suffix, 5, 7))
print("3. ", str.startswith(prefix))
print("4. ", str.capitalize())
print("5. ", str.capitalize().startswith(prefix))

print("")

str = "this is string example....wow!!!";
substr = "exam";
print("1. ", str.find(substr))
print("2. ", str.find(substr, 10))
print("3. ", str.find(substr, 20))
print("4. ", str.index(substr, 10))
#print("5. ", str.index(substr, 20))
print("6. ", str.find("test"))
print("")

str = "THIS is string example....wow!!!"; 
print("1. ", str.islower())
print("2. ", str.lower())
print("3. ", str.lower().islower())

print("")
str = "this is string example....wow!!!"; 
print("1. ", str.islower())
print("2. ", str.upper())
print("3. ", str.upper().capitalize())
print("4. ", str.upper().capitalize().islower())
print("5. ", str.upper().isupper())


print("")

str = "       "; 
print(str.isspace())

str = "This is string example....wow!!!";
print(str.isspace())

str = "This is string is example...is .wow!!!";
print("")
print(str)
print(str.replace("is", "was"))
print(str)

print("")
str = "This is string is example...is .wow!!!";
print("1. ", str)
print("2. ", str.replace("is", "was", 1)) #Number of occurences to replace
print("3. ", str.replace("is", "was", 2)) #Number of occurences to replace
print("4. ", str.replace("is", "was", -1)) #Number of occurences to replace
print("5. ", str[5:].replace("is", "was")) #Number of occurences to replace
print("")

str = "          this is string           example....wow!!!     ";
print("1. ", str)
print("1. ", len(str))
print("2. ", str.rstrip())
print("2. ", len(str.rstrip()))
print("3. ", str.lstrip())
print("3. ", len(str.lstrip()))
print("4. ", str.strip())
print("4. ", len(str.strip()))

print("")

str = "88888888this is string example....wow!!!8888888888888888888888";
print(str)
print(str.rstrip('8'))
print((str.rstrip('8')).lstrip('8'))
print((str.rstrip('8')).lstrip('8').lstrip("th"))
print(str.strip('8'))

str = "88888888this is string example....wow!!!8888888888abc888888888888";
#output should be str = "this is string example....wow!!!abc";
print(str)
substr = "abc"
print(str.lstrip('8').rstrip('8').rstrip(substr).rstrip('8')+substr)
print(str.strip('8'))

#Number with tabs, single space and multiple spaces
phnum = "	      990 2096 750   	       "
print(phnum)
print(phnum.split())
print(phnum.split()[1])
phnum = "".join(phnum.split())
print(phnum)

print("")
str = "Line1-ab cdef \nLine2-abc\nLine,4-abcd";
print(str)
print(str.split())
print(type(str.split()))
print(str.split(' ', 1))
print(str.split(' ', 2))

print("")
email = "bhagavansprasad@gmail.com"
print(email)
print(email.split('@'))

username = email.split('@')[0]
dname = email.split('@')[1]
print(username)
print(dname)

username,dname = email.split('@')
print(username)
print(dname)
exit(1)

