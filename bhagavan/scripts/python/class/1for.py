i = 1 
teststr = "How are you"

print teststr[0]
print teststr[1]

i = 0
while (i <= 10):
    print  teststr[i],
    i += 1

print ""


print teststr
zzzchar = 't'
for zzzchar in teststr:
    print zzzchar 

print ""

mywords = ['hello', 'how', 'are', 'you']

for tword in mywords:
	print tword, 
        print tword[0], tword[1], tword[2]

print ""

for word in mywords:
    print word, 
    i = 0
    for mychar in word:
	print i, ':', mychar, 
	i = i + 1
    print ""

