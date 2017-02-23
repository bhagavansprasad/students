dict = {'Name': 'Zara', 'Age': 7, 'Class': 'First', 'phone': ['9902000000', '900000000']}

print "dict['Name']: ",  dict['Name']
print "dict['Age']: ",   dict['Age']
print "dict['Class']: ", dict['Class']
print "dict['phone']: ", dict['phone']
print "dict['phone']: ", dict['phone'][0]
print "dict['phone']: ", dict['phone'][0][0]

print "dict['Age']  : ", type(dict['Age'])
print "dict['Class']: ", type(dict['Class'])
print "dict['phone']: ", type(dict['phone'])
print "dict['phone']: ", type(dict['phone'][0])
print "dict['phone']: ", type(dict['phone'][0][0])

print dict
print type(dict)

dict = {'Name': 'Zara', 'Age': 7, 'Class': 'First'}
dict['Age'] = 8;
dict['School'] = "DPS School";
print "dict['Age']: ", dict['Age']
print "dict['School']: ", dict['School']

print dict

dict = {'Name': 'Zara', 'Age': 7, 'Class': 'First'}
print dict
del dict['Name'];
#dict.clear();
#del dict ;
print dict
print "dict['Age']: ", dict['Age']
