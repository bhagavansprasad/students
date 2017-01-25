list1 = ['physics', 'chemistry', '1997', '2000'];
list2 = [1, 2, 3, 4, 5, 2, 5, 1 ];
list3 = ["a", "b", "c", "d"]

print "list1[0]: ", list1[0]
print "list2[1:5]: ", list2[1:5]

print list1[2]
list1[2] = 2001;
print list1[2]

del list1[2];
print list1

list1.append(10)
print list1

print list2.count(2)

list1.extend(list2)

print list1
print list2
print list1.index('chemistry')
print list1.index('physics')

list1.pop(1)
print list1

list1.sort()
print list1

''' 
''' 
