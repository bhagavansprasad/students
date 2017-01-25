
str = "this    is string example....wow!!!";

''' 
print "str.capitalize() : ", str.capitalize()

print str
str =  str.capitalize()
print str
print ""



sub = "i";
print "str.count(sub, 4, 40) : ", str.count(sub, 4, 40)
print "str.count(sub) : ", str.count(sub)
sub = "wow";
print "str.count(sub) : ", str.count(sub)
print "str.len() :",len(str)

print ""
print str



suffix = "wow!!!";
print str.endswith(suffix)

print ""
print str
suffix = "is";
prefix = "This";
print str.endswith(suffix)
print str.endswith(suffix, 5, 10)
print str.startswith(prefix)
print str.startswith(prefix)
print str.capitalize().startswith(prefix)

print ""


str2 = "exam";
print str.find(str2)
print str.find(str2, 10)
print str.find(str2, 40)

print ""
print str.index(str2)
print str.index(str2, 10)

print ""

str = "THIS is string example....wow!!!"; 
print str.islower()
print str.lower().islower()

str = "this is string example....wow!!!";
print str.islower()
print str.upper().capitalize().islower()
print str.upper().isupper()

print ""


str = "       "; 
print str.isspace()

str = "This is string example....wow!!!";
print str.isspace()


str = "This is string is example...is .wow!!!";
print ""
print str
print str.replace("is", "was")
print str
print str.replace("is", "was", 2)
print ""


str = "     this is string example....wow!!!     ";
print str,
print "xxxx"
print str.rstrip(),
print "xxxx"
str = "88888888this is string example....wow!!!8888888";
print str.rstrip('8')
print (str.rstrip('8')).lstrip('8')
print (str.rstrip('8')).lstrip('8').lstrip("th")

print ""
str = "Line1-abcdef \nLine2-abc \nLine4-abcd";
print str
print str.split()
print str.split(' ', 1 )
print str.split(' ', 2 )


email = "bhagavansprasad@gmail.com"
print email.split('@')
username = email.split('@')[0]
dname = email.split('@')[1]
print username
print dname
username,dname = email.split('@')
print username
print dname
''' 

print ""
str = "Line1-a b c d e f\nLine2- a b c\n\nLine4- a b c d";
print str.splitlines( )
print str.splitlines( 0 )
print str.splitlines( 3 )
print str.splitlines( 4 )
print str.splitlines( 5 )
exit(1);
