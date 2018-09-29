import string
porting_string = ["print", "print ("]

ignore_list = [
	"#",
	"/",

]
#012345
#print    ("560103")

test_strings = [
	"print'Aura Networks'",
	"print'560103'",
	'print "560103"',
	'print ("560103")',
	'print xyz("560103")',
	'print    ("560103")',
	'print                                  ("560103")',
	'myprint                                 ("560103")',
	'print("560103")',
	'printing my line',
	'#print "temp line"',
	'#    print "temp line"',
	' #    print "temp line"',
	'Hi I am printing my document',
	"B ", 
	"print", 

	"print '560103'",
	"def print_all_files_recursively(path):"
	]

def python_port2x_to_3x(line):
	line = line.strip()
	for byte in ignore_list:
		if (line[0] == byte):
			return False

	if(line.startswith("print") == True):
		j = len("print")

		if (line[len("print")] == ' '):
			while (line[j] == ' '):
				j=j + 1
			if (line[j] == "'" or line[j] == '"'):
				return True
		else:
			if (line[j] == "'" or line[j] == '"'):
				return True

	return False


i = 1
for nstr in test_strings:
	print (i, ":", python_port2x_to_3x(nstr), ":", nstr)
	i = i + 1


	'''

	if((line.startswith((" #print","printing","print(","H","def","myprint","print(","print x","print(                 ")))):
		print (line+" ")
	else:
		new_string = string.replace(line,porting_string[0], porting_string[1])
	 	new_string = new_string  + ")"
		print (new_string)
	'''


