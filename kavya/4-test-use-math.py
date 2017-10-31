#import mymath
#from mymath import is_prime, is_even, is_odd
#from mymath import *
import mymath

n = 5

if (is_prime(n)):
    print n, "Prime"
else:
    print n, "NOT Prime"

if (is_even(n) == 1):
    print n, "EVEN"
else:
    print n, "ODD"

if (is_odd(n) == 1):
    print n, "EVEN"
else:
    print n, "ODD"


