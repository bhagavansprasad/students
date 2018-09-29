import sys
import amath
sys.path.append('/home/bhagavan/training/scripts/python/class/11-Modules/mod-lib')
import fact



n = 17
#if (is_prime(n)):
if (amath.is_prime(n)):
    print (n, "Prime")
else:
    print (n, "NOT Prime")

print ("Factorial value of %d, is :%d" % (n, fact.factorial(n)))
