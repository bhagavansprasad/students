i = 1 
teststr = "How are you"

print teststr[0]
print teststr[1]

print teststr
for mychar in teststr:
    print mychar, 

print ""
print ""

mywords = ['hello', 'how', 'are', 'you']

for word in mywords:
	print word, 
        print word[0], word[1], word[2]

print ""
for word in mywords:
    print word, 
    for mychar in word:
	print i, ':', mychar, 
	i = i + 1
    print ""

