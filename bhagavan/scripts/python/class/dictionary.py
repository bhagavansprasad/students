
my_dict = {'Name': 'Aura', 'Age': 5, 'Location': 'Bangalore'}

print "my_dict['Name']: ", my_dict['Name']
print "my_dict['Age']: ", my_dict['Age']

print my_dict

my_dict['Name'] = 'saketh'
my_dict['Age'] = 15

print my_dict

del my_dict['Name'];

print my_dict

my_dict['Name'] = 'Vachan';

print my_dict

my_dict.clear();   

print my_dict

del my_dict ;     

# empty dictionary
my_dict = {}
print my_dict

# dictionary with integer keys
my_dict = {1: 'apple', 2: 'ball', 'ball':'red'}
print my_dict[1]
print my_dict[2]
print my_dict['ball']


# dictionary with mixed keys
my_dict = {'name': 'John', 1: [2, 9, 7, 4, 3]}
print my_dict['name']
print my_dict[1][0]
print my_dict[1][0:3]
print my_dict[1][0:3][1]

print type(my_dict[1])

for value in my_dict[1]:
    print value,

print " "
# using dict()
my_dict = dict({1:'apple', 2:'ball'})

print my_dict
print my_dict[1]

# from sequence having each item as a pair
my_dict = dict([(1,'apple'), (2,'ball')])
print my_dict
print my_dict[2]


customers = [{"uid":1,"name":"Vachan"},
             {"uid":2,"name":"Ram"},
             {"uid":3,"name":"Saketh"},
            ]

print customers

for cust in customers:
    print cust["uid"], cust["name"]

for cust in customers:
    cust["password"]="123456"

print customers

exit(1)


