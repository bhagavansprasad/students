def dump_object_help(obj):
	for member in dir(obj):
		print("print \"%-20s :\", obj.%s" %  (member, member))

	        '''
		if (member.find("_") == -1):
			print member
			#print dir(member.__doc__)
			print "obj.%s" % (member)
			#hobj = "obj.%s" % (member)
			help(print "obj.%s" % (member))
		'''
