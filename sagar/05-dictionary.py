'''
<student>
    <name> aura </name>
    <class> 5 </class>
    <marks> 
        <s1> 45 </s1>
        <s2> 40 <s2>
    </marks>
</student>

<student>
    <name> aura </name>
    <class> 10 </class>
    <marks> 
        <s1> 45 </s1>
        <s2> 40 <s2>
    </marks>
</student>
'''

'''
student_data = {
  student[
            {
            "name":"aura",
            "class":5,
            "marks":[
                    {"s1":45},
                    {"s2":40}
                ]
            },
            {"name":"temp",
            "class":10,
            "marks":[
                {"s1":45},
                {"s2":40}
                ]
            },
            ]
        }
'''

#json

atomic_elements = {
	"H": "hydrogen",
	"He": "helium",
	"Li": "lithium",
	"C": "carbon",
	"O": "oxygen",
	"P": "phosp",
	"N": "nitrogen"
}

print(atomic_elements)
print(atomic_elements["C"])
print(atomic_elements["O"])
print("")


print("O" in atomic_elements, "U" in atomic_elements)
print("o" in atomic_elements)

if ("O" in atomic_elements):
    print("'O' Symbol is available")
    print(atomic_elements["O"])

if ("U" in atomic_elements):
    print("'U' Symbol is available")
else:
    print("'U' Symbol is NOT available")

print("oxygen" in atomic_elements)

print(atomic_elements.get("P", "The item 'P' Not available"))
print(atomic_elements.get("c", "The item 'c' Not available"))
atomic_elements.update( {"P": "Phosphorous", "S": "sulfur"} )
print(atomic_elements)
del atomic_elements['C']
print(atomic_elements)
#print (atomic_elements["C"])

print(list(atomic_elements.keys()))
print(list(atomic_elements.values()))
print(list(atomic_elements.values())[0])
print(list(atomic_elements.items()))
print(list(atomic_elements.items())[0])

print("")
dict = {'Name': 'Zara', 'Age': 7, 'Class': 'First', 'phone': ['9902000000', '900000000']}
print("dict['Name']: ",  dict['Name'])
print("dict['Age']: ",   dict['Age'])
print("dict['Class']: ", dict['Class'])
print("dict['phone']: ", dict['phone'])
print("dict['phone']: ", dict['phone'][1])
print("dict['phone']: ", dict['phone'][0][0])

print(type(dict))
print(dir(dict))

atomic_number_to_name = {
    1: "hydrogen",
    6: "carbon",
    7: "nitrogen",
    8: "oxygen",
}

print(atomic_number_to_name)
print(atomic_number_to_name[1])
print(atomic_number_to_name[8])

nobel_prize_winners = {
    (1979, "physics"): ["Glashow", "Salam", "Weinberg"],
    (1962, "chemistry"): ["Hodgkin"],
    (1984, "biology"): ["McClintock"],
}
print(nobel_prize_winners[(1979, "physics")])

states = {
    'Andhra Pradesh': 'AP',
    'Karnataka': 'KA',
    'Telangana': 'TS',
    'Tamilnadu': 'TN',
    'Gujarath': 'GJ',
    'Maharashtra': 'MH'
}

cities = {
    'MH': 'Mumbai',
    'AP': 'Amaravathi',
    'TS': 'Hyderabad',
    'TN': 'Chennai',
    'KA': 'Benguluru'
}

print(states)
print(cities)

states['Odisha'] = 'OR'
print(states)

cities['OR'] = 'Bhuvaneswar'
cities['GJ'] = 'Ahemadabad'

print(states)
print(cities)

print('-' * 10)
print("MH State has: ", cities['MH'])
print("OR State has: ", cities['OR'])

print('-' * 10)
print("Karnataka's abbreviation is   : ", states['Karnataka'])
print("Maharashtra's abbreviation is : ", states['Maharashtra'])
print("Maharashtra's abbreviation is : ", states['Andhra Pradesh'])

# do it by using the state then cities dict
print('-' * 10)
print("Maharashtra has: ", cities[states['Maharashtra']])
print("Gurarath has: ",    cities[states['Gujarath']])

print('-' * 10)
for state, abbrev in list(states.items()):
    print("'%-15s' is abbreviated '%s'" % (state, abbrev))

# print every city in state
print('-' * 10)
for abbrev, city in list(cities.items()):
    print("'%s' has the city '%s'" % (abbrev, city))

# now do both at the same time
print('-' * 10)
for state, abbrev in list(states.items()):
    print("'%-15s' state is abbreviated '%s' and has city '%s'" % (state, abbrev, cities[abbrev]))

print('-' * 10)
# safely get a abbreviation by state that might not be there
state = states.get('Kerala')
#print (states['Kerala'])
print(state)

if not state:
    print("Sorry, no Kerala.")

# get a city with a default value
city = cities.get('KR', 'Does Not Exist')
print("The city for the state 'KR' is: %s" % city)

print(type(city))

my_dict = {'Name': 'Aura', 'Age': 5, 'Location': 'Bangalore'}
print(my_dict)
my_dict.clear();   
print(my_dict)

del my_dict ;     
#print (my_dict)

# empty dictionary
my_dict = {}
print(my_dict)
exit(1)

