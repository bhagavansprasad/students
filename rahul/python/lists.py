import pdb
pdb.set_trace()
ids = ['9pti', "2plv", "1crn"]
print ids

ids.append("1alm")
print ids


ids.append(10)
ids.append(ids[4] + 10)

print ids

ids[5] = ids[5] + 20

print ids

del ids[0]
print ids

ids.sort()
print ids

ids.reverse()
print ids


ids.insert(2, "9pti")
print ids

list1 = ['physics', 'chemistry', '1997', '2000'];
list2 = [1, 2, 3, 2, 5, 2, 5, 2 ];
list3 = ["a", "b", "c", "d"]

print "list1[0]: ",   list1[0]
print "list2[1:5]: ", list2[1:5]

print list1
print list1[2]
list1[2] = 2001;
print list1[2]
print list1

print list1
del list1[2];
print list1

list1.append(10)
print list1


print list2
print list2.count(2)
print len(list2)

print "list1: ",   list1
print "list2: ",   list2
list1.extend(list2) #this adds all list2 elements to list1

print "list1: ",   list1
print "list2: ",   list2

print list1.index('chemistry')
print list1.index('physics')


print "list2: ",   list2

list2.pop()
list2.pop()
list2.pop()
list2.append(9)
print "list2: ",   list2
list2.pop(2)
list2.pop(0)
list2.pop(-1)
#list2.pop(10)
print "list2: ",   list2

list2.sort()
print "list2: ",   list2

exit(1)
