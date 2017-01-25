tuple1, tuple2 = (123, 'ab'), (123, 'abc')

print cmp(tuple1, tuple2)
print cmp(tuple2, tuple1)
print cmp(tuple1, ('abcd',))

tuple3 = tuple2 + (823,);
print tuple3
print cmp(tuple2, tuple3)

print "First tuple length : ",  len(tuple1)
print "Second tuple length : ", len(tuple2)

print "Max value element : ", max(tuple1)
print "Max value element : ", max(tuple2)

print "min value element : ", min(tuple1)
print "min value element : ", min(tuple2)


aList = (123, 'xyz', 'zara', 'abc');
aTuple = tuple(aList)
print "Tuple elements : ", aTuple

