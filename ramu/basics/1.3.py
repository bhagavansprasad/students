a=626
t=a
c=0
c=(c*10)+a%10
a=a/10
c=(c*10)+a%10
a=a/10
c=(c*10)+a%10
a=a/10
if(c==t):
   print "palindrome"
else:
   print "not palindrome"
