import string
porting_string = ["print", "print ("]

def python_port2x_to_3x(line):
	if((line.startswith(("#print","printing","print(","H","def","myprint","print(","print x","print(                 ")))):
		print (line+" ")
	else:
		new_string = string.replace(line,porting_string[0], porting_string[1])
	 	new_string = new_string  + ")"
		print (new_string)
test_strings = [
	"print'Aura Networks'",
	"print'560103'",
	'print "560103"',
	'print ("560103")',
	'print ("560103")',
	'print xyz("560103")',
	'print    ("560103")',
	'print                                  ("560103")',
	'myprint                                 ("560103")',
	'myprint                                 ("560103")',
	'print("560103")',
	'printing my line',
	'#print "temp line"',
	'Hi I am printing my document',
	"print '560103'",
	"def print_all_files_recursively(path):"
	]

for nstr in test_strings:
	(python_port2x_to_3x(nstr))
