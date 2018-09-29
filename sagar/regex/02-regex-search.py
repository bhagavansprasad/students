import re

#"w" - Specifies charactar
s1 = "we doing We do     not   need   ACTS   but  Action We temp"
s2 = "Once we do we decide we have to do something, we can go miles ahead"
s3 = "We re are not here for any positions but for a responsibility"
s4 = "In  my life mission and passsion is everything.. Even if i was a municipal chairman, work as hard as a CM"
s5 = "This number  12345 contains  5 degits, 346 three,  86 two, and abcd 2345 xyz, aura05Bng also  string"
s6 = "My email ID is bhagavan@auranetworks.in and other enquiry@auranetworks.in my domain is auranetworks  bhag@aura,in"
s7 = 'email hrdeportment-s@auranetworks.in and other support@auranetworks.in are sits main cabin bhag@au-ra.in'

regex = r'We \w\w'
print("search -- '%s' -- '%s' " % (regex, s1))
match = re.search(regex, s1)
if match:                      
    print('Found :', match.group())
else:
    print('Not Found')
print("")

regex = r'we \w\w\w'
print("search -- '%s' -- '%s' " % (regex, s2))
match = re.search(regex, s2)
if match:                      
    print('Found :', match.group())
else:
    print('Not Found')
print("")

regex = r'.re'
print("search -- '%s' -- '%s' " % (regex, s3))
match = re.search(regex, s3)
if match:                      
    print('Found :', match.group())
else:
    print('Not Found')
print("")

regex = r'.re'
print("finditer -- '%s' -- '%s' " % (regex, s3))
for match in re.finditer(regex, s3):
    print(match.group())
print("")

regex = r'..re'
print("search -- '%s' -- '%s' " % (regex, s3))
match = re.search(regex, s3)
if match:                      
    print('Found :', match.group())
else:
    print('Not Found')
print("")

regex = r'.is'
print("search -- '%s' -- '%s' " % (regex, s4))
match = re.search(regex, s4)
if match:                      
    print('Found :', match.group())
else:
    print('Not Found')
print("")

regex = r'.is'
print("findall -- '%s' -- '%s' " % (regex, s4))
match = re.findall(regex, s4)
if match:                      
    print('Found :', match)
else:
    print('Not Found')
print("")

regex = r'..is'
print("search -- '%s' -- '%s' " % (regex, s4))
match = re.search(regex, s4)
if match:                      
    print('Found :', match.group())
else:
    print('Not Found')
print("")

regex = r'is'
print("search -- '%s' -- '%s' " % (regex, s4))
match = re.search(regex, s4)
if match:                      
    print('Found :', match.group())
else:
    print('Not Found')
print("")

regex = r'\d\d\d'
print("findall -- '%s' -- '%s' " % (regex, s5))
match = re.findall(regex, s5)
if match:                      
    print('Found :', match)
else:
    print('Not Found')
print("")

regex = r'\w\w\w'
print("findall -- '%s' -- '%s' " % (regex, s1))
match = re.findall(regex, s1)
if match:                      
    print('Found :', match)
else:
    print('Not Found')
print("")

regex = r'...'
print("findall -- '%s' -- '%s' " % (regex, s1))
match = re.findall(regex, s1)
if match:                      
    print('Found :', match)
else:
    print('Not Found')
print("")

regex = r'ss+'
print("findall -- '%s' -- '%s' " % (regex, s4))
match = re.findall(regex, s4)
if match:                      
    print('Found :', match)
else:
    print('Not Found')
print("")

regex = r'\s\s\d\d'
print("findall -- '%s' -- '%s' " % (regex, s5))
match = re.findall(regex, s5)
if match:                      
    print('Found :', match)
else:
    print('Not Found')
print("")

regex = r'\s*\d\d\s'
print("findall -- '%s' -- '%s' " % (regex, s5))
match = re.findall(regex, s5)
if match:                      
    print('Found :', match)
else:
    print('Not Found')
print("")

regex = r'\s.\d\d\s'
print("findall -- '%s' -- '%s' " % (regex, s5))
match = re.findall(regex, s5)
if match:                      
    print('Found :', match)
else:
    print('Not Found')
print("")

regex = r'^This'
print("findall -- '%s' -- '%s' " % (regex, s5))
match = re.findall(regex, s5)
if match:                      
    print('Found :', match)
else:
    print('Not Found')
print("")

regex = r'\w+@\w+'
print("findall -- '%s' -- '%s' " % (regex, s6))
match = re.findall(regex, s6)
if match:
    print(match)
print("")

#regular expression for validating email ID
regex = r'\w+@\w+\.\w+'
print("findall -- '%s' -- '%s' " % (regex, s6))
match = re.findall(regex, s6)
if match:
    print(match)
print("")

regex = r'([\w.-]+)@([\w.-]+)'
print("search -- '%s' -- '%s' " % (regex, s7))
match = re.search(regex, s7)
if match:
    print(match.group())   
    print(match.group(1))  
    print(match.group(2))  
print("")

regex = r'([\w.-]+)@([\w.-]+)'
print("findall -- '%s' -- '%s' " % (regex, s7))
match = re.findall(regex, s7)
if match:
    print(match)
print("")

regex = r'\s\s+'
print("findall -- '%s' -- '%s' " % (regex, s1))
match = re.findall(regex, s1)
print(re.sub(regex, ' ', s1))
if match:
    print(match)
print("")

regex = r'ACTS'
print("search -- '%s' -- '%s' " % (regex, s1))
match = re.search(regex, s1)
if match:
    print(match.start())
    print(match.end())
print("")

str = "bhagavan|account-1000013@foreman.auradev.com"
#regex = r'\|\w+\@'
regex = r'\|[\w.-]+@'
print("search -- '%s' -- '%s' " % (regex, str))
match = re.search(regex, str)
if match:
    print(match.start())
    print(match.end())
    print(str[:match.start()]+str[match.end()-1:])
print("")

exit(1)
