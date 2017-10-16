     porting_strins = ["print", "print ("]

def python_port2x_to_3x(line):
	new_string = line.replace(porting_strins[0], porting_strins[1])
	new_string = new_string  + ")" 

	return new_string

test_strings = [
	"print'Aura Networks'",
	"print'560103'",
	'print "560103"',
	'print ("560103")',
	'	print ("560103")',
	'print xyz("560103")',
	'print    ("560103")',
	'print                                 ("560103")',
	'myprint                                 ("560103")',
	'	myprint                                 ("560103")',
	'print("560103")',
	'printing my line',
	'#print "temp line"',
	'Hi I am printing my document',
	"print '560103'",
	"def print_all_files_recursively(path):"
	]

for nstr in test_strings:
	print (python_port2x_to_3x(nstr))
