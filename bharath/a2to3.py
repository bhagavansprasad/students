import string
porting_string = ["print", "print ("]

ignore_list = [
	"#",
	"'",
	'"'
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
	"print '560103'",
	"def print_all_files_recursively(path):"
	"print", 
	""
	]


def python_port2x_to_3x(line):
	prefix = "print"
	line = line.strip()

	for byte in ignore_list:
		if (line == byte):
			return False

	if(line.startswith(prefix) == True):
		j = len(prefix)
		if (line[len(prefix)] == "'"):
			while (line[j] == " "):
				j = j + 1
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

