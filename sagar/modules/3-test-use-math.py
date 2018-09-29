import sys
from amath import is_prime

sys.path.append('/home/bhagavan/students/sagar/modules')

#import fact

n = 17
#if (amath.is_prime(n)):
if (is_prime(n)):
    print (n, "Prime")
else:
    print (n, "NOT Prime")

print ("Factorial value of %d, is :%d" % (n, fact.factorial(n)))

