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
	[False, "print"], 
	[True, 'print "560103"'],
	[True, "print '560103'"],
	[True, "print'Aura Networks'"],
	[True, "print'560103'"],
	[False, 'print ("560103")'],
	[False, 'print xyz("560103")'],
	[False, 'print    ("560103")'],
	[False, 'print                                  ("560103")'],
	[False, 'myprint                                 ("560103")'],
	[False, 'print("560103")'],
	[False, 'printing my line'],
	[False, '#print "temp line"'],
	[False, '#    print "temp line"'],
	[False, ' #    print "temp line"'],
	[False, 'Hi I am printing my document'],
	[False, "B "], 
	[False, "def print_all_files_recursively(path):"],
	[False, ""]
	]


def python_port2x_to_3x(line):
	prefix = "print"
	line = line.strip()

	for byte in ignore_list:
		if (line == byte):
			return (False, -1)

	if(line.startswith(prefix) == True):
		j = len(prefix)

		if (len(prefix) == len(line)):
			return (False, -1)

		if (line[len(prefix)] == " "):
			while (line[j] == " "):
				j = j + 1
			if (line[j] == "'" or line[j] == '"'):
				return (True, j)
		else:
			if (line[j] == "'" or line[j] == '"'):
				return (True, j)

	return (False, -1)


''' 
i = 1
for nstr in test_strings:
	try:
		result = python_port2x_to_3x(nstr[1])
		assert(result == nstr[0])
	except:
		#print (i, ":", "FAIL ---", result, ":", nstr[1])
		print (i, ":", "FAIL ---", result, ":", nstr[1])
	else:
		#print (i, ":", "PASS ---", result, ":", nstr[1])
		print (i, ":", "PASS ---", result, ":", nstr[1])

		
	i = i + 1
''' 

i = 1
for nstr in test_strings:
	(result, pos) = python_port2x_to_3x(nstr[1])
	if (result == True):
		print ("-->%d:%s, pos :%d" % (i,  nstr[1], pos))
		ts = nstr[1][:pos] + '(' + nstr[1][pos:] + ')'
		print ("     %s" % (ts))
	i = i + 1
	
