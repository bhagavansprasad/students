'''
symbol_to_name = {
	"H": "hydrogen",
	"He": "helium",
	"Li": "lithium",
	"C": "carbon",
	"O": "oxygen",
	"N": "nitrogen"
}

print symbol_to_name
print symbol_to_name.keys()
print symbol_to_name.values()
print symbol_to_name.items()

print symbol_to_name["C"]

print "O" in symbol_to_name, "U" in symbol_to_name

if ("O" in symbol_to_name):
    print "Symbol is available"

if ("U" in symbol_to_name):
    print "Symbol is available"
else:
    print "Symbol is NOT available"

print "oxygen" in symbol_to_name

#print symbol_to_name["P"]
print symbol_to_name.get("P", "Not available")
print symbol_to_name.get("C", "Not available")
print symbol_to_name.keys()
print symbol_to_name.values()
print symbol_to_name.update( {"P": "phosphorous", "S": "sulfur"} )
print symbol_to_name.items()
del symbol_to_name['C']
print symbol_to_name

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
'''

atomic_number_to_name = {
    1: "hydrogen",
    6: "carbon",
    7: "nitrogen",
    8: "oxygen",
}

nobel_prize_winners = {
    (1979, "physics"): ["Glashow", "Salam", "Weinberg"],
    (1962, "chemistry"): ["Hodgkin"],
    (1984, "biology"): ["McClintock"],
}

print atomic_number_to_name[1]
print nobel_prize_winners[(1979, "physics")]

states = {
    'Oregon': 'OR',
    'Florida': 'FL',
    'California': 'CA',
    'New York': 'NY',
    'Michigan': 'MI'
}

cities = {
    'CA': 'San Francisco',
    'MI': 'Detroit',
    'FL': 'Jacksonville'
}

print states
print cities


cities['NY'] = 'New York'
cities['OR'] = 'Portland'

print states
print cities


print '-' * 10
print "NY State has: ", cities['NY']
print "OR State has: ", cities['OR']

print '-' * 10
print "Michigan's abbreviation is: ", states['Michigan']
print "Florida's abbreviation is: ", states['Florida']

# do it by using the state then cities dict
print '-' * 10
print "Michigan has: ", cities[states['Michigan']]
print "Florida has: ", cities[states['Florida']]

print '-' * 10
for state, abbrev in states.items():
    print "%s is abbreviated %s" % (state, abbrev)

# print every city in state
print '-' * 10
for abbrev, city in cities.items():
    print "%s has the city %s" % (abbrev, city)

# now do both at the same time
print '-' * 10
for state, abbrev in states.items():
    print "%s state is abbreviated %s and has city %s" % (state, abbrev, cities[abbrev])

print '-' * 10
# safely get a abbreviation by state that might not be there
state = states.get('Texas')

if not state:
    print "Sorry, no Texas."

# get a city with a default value
city = cities.get('TX', 'Does Not Exist')
print "The city for the state 'TX' is: %s" % city

print type(city)
print dir(city)

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



