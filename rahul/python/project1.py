#import pdb
#pdb.set_trace()
student = ["bhagavan", "Bhagavan Prasad", "1000", "1001", "9902096750", " ", "Bommanahalli", "  ", "enabled", ""]

for details in student:
        print details, " ", 

temp_list = []


students = [
    ["bhagavan", "Bhagavan Prasad", "1000", "1001", "9902096750", "", "Bommanahalli", "", "enabled"],
    ["sai", "Sai Kumar", "1000", "1001", "9945708707", "", "Bangalore", " ", "enabled"],
    ["pavan", "Pavan Kumar", "1500", "1001", "9886304081", "", "Bommanahalli", "", "enabled"],
    ["test users", "Harsha Vardhan", "1501", "1001", "9902369277", "", "Bommanahalli", "", "enabled"],
    ["harsha", "Harsha Vardhan", "1501", "1001", "9902369277", "", "Bommanahalli", "", "enabled"],
    ["mohansai", "Mohan Sai", "1503", "1001", "9945708707", "", "Bommanahalli", "", "enabled"],
	["rahul", "Rahul Rohit", "1504", "1002", "9199976255","","Bellandur","","disabled"],
	["rohit", "Rohit Kumar", "1505", "1003", "9199976255","","Bellandur","","disabled"],
]
print ""

for student in students:
	if (student[4] in temp_list):
		print "Duplicate :", student[4]
	else:
		temp_list.append(student[4])

''' 
for student in students:
	if (student[4] not in temp_list):
		temp_list.append(student[4])

''' 
print "==============="
print temp_list
print "==============="

exit(1)

