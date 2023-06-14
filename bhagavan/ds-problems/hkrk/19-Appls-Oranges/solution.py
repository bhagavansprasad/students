#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'countApplesAndOranges' function below.
#
# The function accepts following parameters:
#  1. INTEGER s
#  2. INTEGER t
#  3. INTEGER a
#  4. INTEGER b
#  5. INTEGER_ARRAY apples
#  6. INTEGER_ARRAY oranges
#

def countApplesAndOranges1(s, t, a, b, apples, oranges):
    # Write your code here
    ac = 0
    oc = 0
    print(s, t, a, b, apples, oranges)
    hp = [i for i in range(s, t+1)]
    print(f"hp :{hp}")
    print("Apples...")
    for i in apples:
        # print(a+i, end=" ")
        if (a+i in hp):
            print(f"A: {a+i}")
            ac = ac + 1
        

    print("\n")
    print("Oranges...")
    for i in oranges:
        # print(b+i, end=" ")
        if (b+i in hp):
            print(f"O: {b+i}")
            oc = oc + 1
        
    print("\n")
    print(ac)
    print(oc)

def countApplesAndOranges(s, t, a, b, apples, oranges):
    # Write your code here
    ac = 0
    oc = 0
    hp = [i for i in range(s, t+1)]
    for i in apples:
        if (a+i >= s and a+i <= t):
            ac = ac + 1
        
    for i in oranges:
        if (b+i >= s and b+i <= t):
            oc = oc + 1
        
    print(ac)
    print(oc)
    
if (__name__ == "__main__"):
    s = 7; t = 10; a = 4; b = 12; m = [2, 3, -4]; n = [3, -2, -4]
    # s = 7; t = 11; a = 5; b = 15; m = [-2, 2, 1]; n = [5, -6]
    countApplesAndOranges(s, t, a, b, m, n)