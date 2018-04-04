import random

def get_match_Winner(tset):
    print (tset)
    randnum = random.randint(0, 1)
    return (tset[randnum])
    
print (get_match_Winner(('A', 'B')))
