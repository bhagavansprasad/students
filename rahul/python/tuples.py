tuple1 = (123, 'abcdef')
tuple2 = (123, 'abb')

print cmp(tuple1, tuple2)
print cmp(tuple2, tuple2)
print cmp(tuple2, tuple1)
print cmp(tuple1, (123, 'ab'))

print ""

print cmp((123, 'abc'), (123, 'abc'))
print cmp((123, 'abc'), (123, 'abz'))
print cmp((123, 'abc'), (123, 'aba'))
print cmp((123, 'abc'), (123, 'abaxyz')) #here 123 is integer
print cmp((123, 'abc'), (123, 'abdxyz'))
print cmp((123, 'abc'), ('123', 'abdxyz'))#here '123'is string

print ""

#tuple3 = tuple2 + ('823')
tuple3 = tuple2 + tuple('823')
print tuple3

print cmp(tuple2, tuple3)

print ""
tuple1 = tuple('823')
print tuple1
print type(tuple1)

tuple1 = tuple("823")
print tuple1
print type(tuple1)

tuple1 = (123, '283')
print tuple1
print type(tuple1)

print tuple1[0]
print type(tuple1[0])
print tuple1[0]+5
print int(tuple1[1])+5

print "First tuple length : ",  len(tuple1)
print "Second tuple length : ", len(tuple2)

print "Max value element : ", max(tuple1)
print "Max value element : ", max(tuple2)

print "min value element : ", min(tuple1)
print "min value element : ", min(tuple2)


aList = (123, 'xyz', 'zara', 'abc');
aTuple = tuple(aList)
print "Tuple elements : ", aTuple

tup1 = ('physics', 'chemistry', 1997, 2000);
tup2 = (1, 2, 3, 4, 5, 6, 7 );
print "tup1[0]  : ", tup1[0]
print "tup2[1:5]: ", tup2[1:5]

print "tup1  :", tup1
print "tup2  :", tup2
tup1 = (12, 34.56);
tup2 = ('abc', 'xyz');
print "tup1  :", tup1
print "tup2  :", tup2

#tup1[0] = 100;
#tup2.append(4)

print "tup1  :", tup1

tup3 = tup2 + tup1 + tup2 + (2, 3, 4, 5)
print "tup3  :", tup3

tup = ('physics', 'chemistry', 1997, 2000);
print "tup :", tup
#del tup;

print "After deleting tup..."
print "tup :", tup

julia = ("Julia", "Roberts", 1967, "Duplicity", 2009, "Actress", "Atlanta, Georgia")
(name, surname, b_year, movie, m_year, profession, b_place) = julia

print name

months = ('January','February','March','April','May','June', 'July','August','September','October','November','  December')
print "months :", months

x = 8
print months[x]
print len(months)

#months.sort()
print "months :", months
exit(1)
