<<<<<<< HEAD
     porting_strins = ["print", "print ("]
=======
import re
porting_strins = ["print", "print ("]
>>>>>>> d68dca1db041b84c6c8a2484e59d2a552d29ec6b

def python_port2x_to_3x(line):
	regex = r"[^#]print*[^(]"

	match = re.findall(regex, line.strip())
	if match:
		print ("-" * 10, line)
	else:
		print (line)



'''
def python_port2x_to_3x(line):
	regex = r"[^#]print*[^(]"
	new_string = line.replace(porting_strins[0], porting_strins[1])
	new_string = new_string  + ")" 

	return new_string
'''


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
	#print (python_port2x_to_3x(nstr))
	python_port2x_to_3x(nstr)
