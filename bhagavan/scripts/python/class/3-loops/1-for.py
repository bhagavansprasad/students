for x in range(0, 3):
    print "We're on time %d" % (x)

for x in xrange(1, 6):
    for y in xrange(1, 6):
        print '%d * %d = %d' % (x, y, x*y)
    print ""

for x in xrange(5):
    print x
else:
    print 'Final x = %d' % (x)

exit(1)
string = "Hello World"
for x in string:
    print x

collection = ['hey', 5, 'd']
for x in collection:
    print x

list_of_lists = [ [1, 2, 3], [4, 5, 6], [7, 8, 9]]
for list in list_of_lists:
    for x in list:
        print x

i = 1;
j = 1;
words = ['aura', 'networks', 'Bangalore']

for myword in words:
	print i, myword
	for byte in myword:
		print j, byte
		j+=1
	j = 1
	i += 1
	

