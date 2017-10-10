import re

'''
def python_port2x_to_3x_regex(line):
	regex = r'^print\s+\('
	match = re.findall(regex, line)
	if match:                      
		print ('Found :%s--%s' % (match, line))
'''

porting_strins = ["print", "print ("]

def python_port2x_to_3x(line):
	new_string = line.replace(porting_strins[0], porting_strins[1])
	new_string = new_string  + ")" 

	return new_string

test_strings = [
	"print'Aura Networks'",
	"print'VR Chambers'",
	"print'Kadubisanahalli'",
	"print'Bangalore'",
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
	'Hi I am printing my documet',
	"print '560103'",
	"def print_all_files_recursively(path):"
	]

for nstr in test_strings:
	print (python_port2x_to_3x(nstr))
