'''
tuple1 = (123, 'abcdef')
tuple2 = (123, 'abb')

print("")

#tuple3 = tuple2 + ('823')
tuple2 = tuple2 + tuple("ffghf")
print(tuple2)


print("")
tuple1 = ('823')
print(tuple1)
print(type(tuple1))
print("")
tuple1 = (123, '283')
print(tuple1)
print(type(tuple1))

print(tuple1[0])
print(type(tuple1[0]))
print(tuple1[0]+5)

print(type(tuple1[1]))
print(tuple1[1]*5)
print(int(tuple1[1])+5)
#print tuple1[1]+5
print(str(tuple1[0])[0])
print(tuple1[1][0])

tuple1 = (123, '283')
tuple2 = (123, 'abb')
print("First tuple length : ",  len(tuple1))
print("Second tuple length : ", len(tuple2))

tuple1 = ('1', '98346')
tuple2 = ('123', 'abb')
print("tuple1 :", tuple1)
print("tuple2 :", tuple2)
print(dir(tuple1))


print("\n**************************************")
print("Max value element tuple1: ", max(tuple1))
print("Max value element tuple2: ", max(tuple2))

print("min value element : ", min(tuple1))
print("min value element : ", min(tuple2))


print("")
aList = [123, 'xyz', 'zara', 'abc'];
aTuple = tuple(aList)
print("Tuple elements : ", aTuple)


tuple1 = ('1', 98346)
#tuple1[0] = 100;
#tuple1.append(4)

#del tuple1;
print("")
print("tuple1  :", tuple1)

tuple3 = tuple2 + tuple1 + tuple2 + (2, 3, 4, 5)
print("tuple3  :", tuple3)



tuple3 = tuple3 + tuple1
'''

julia = ("Julia", "Roberts", 1967, "Duplicity", 2009, "Actress", "Atlanta, Georgia")
print(julia)
(name, surname, b_year, movie, m_year, profession, b_place) = julia

print(name, surname,m_year)

print("")
months = (' ', 'January','February','March','April','May','June', 'July','August','September','October','November','  December')
print("months :", months)

print("")
x = 8
print(months[x])
print(len(months))

#months.sort()
print("months :", months)
exit(1)
