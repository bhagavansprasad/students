
ids = ["9pti", "2plv", "1crn"]
print(ids)

ids.append("1alm")
print(ids)
ids.append("10")
ids.append(ids[4] + "30")
print(ids)

ids[5] = ids[4] + "20"
print(ids)
del ids[0]
print(ids)

ids.sort()
print(ids)

ids.reverse()
print(ids)

ids.insert(2, "9pti")
print(ids)
exit(1)


list1 = ['physics', 'chemistry', '1997', '2000'];
list2 = [1, 2, 3, 2, 5, 2, 5, 2 ];
list3 = ["a", "b", "c", "d"]

print("list1[0]: ",   list1[0])
print("list2[1:5]: ", list2[1:6])


print(list1)
print(list1[2])
list1[2] = 2001;
print(list1[2])
print(list1)

print(list1)
del list1[2];
print(list1)

list1.append(10)
print(list1)

print(list2)
print(list2.count(2))
print(list2.count(1))
print(list2.count(10))
print(len(list2))

print("list1: ",   list1)
print("list2: ",   list2)
list1.extend(list2) #this adds all list2 elements to list1
print("list1: ",   list1)
print("list2: ",   list2)

print(list1.index('chemistry'))
print(list1.index('physics'))
#print list1.index('maths')


print("list2: ",   list2)
print(list2.pop())

print(list2.pop())
print(list2.pop())
print("list2: ",   list2)
list2.append(9)
print("list2: ",   list2)
print(list2.pop(2))
print(list2.pop(0))
print("list2: ",   list2)
print(list2.pop(-1))
print("list2: ",   list2)
exit(1)

#list2.pop(10)
print("list2: ",   list2)

list2.sort()
print("list2: ",   list2)


list1 = ['physics', 'the subject is english is', 'chemistry', '1997', '2000'];

new_sub = "maths"
if (new_sub in list1):
    print("Found")
else:
    print("Appending")
    list1.append(new_sub)

print(list1)

print("**********************************")

new_sub = "english"
if (new_sub not in list1):
    print("Appending")
    list1.append(new_sub)

print(list1)


new_sub = "English"
if (new_sub not in list1):
    print("Appending")
    list1.append(new_sub)

print(list1)
