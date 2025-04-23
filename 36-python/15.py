s1 = 40; s2 = 50; s3 = 60
s1 = 40; s2 = 50; s3 = 30
s1 = 40; s2 = 30; s3 = 60
s1 = 30; s2 = 40; s3 = 60

if (s1 >= 35 and s2 >= 35 and s3 >= 35):
    print("Congradulations...You are Promoted...")
else:
    print("Sorry...You are not Promoted...")

# True = NON Zero
# False = Zero

# check s1, if >= 35
#   check s2, if >= 35
#       check s3, if >= 35
#           say P
#       otherwise, 
#           say NP
#   otherwise, 
#       say NP
# otherwise, 
#   say NP

s1 = 40; s2 = 50; s3 = 60 # P
s1 = 40; s2 = 50; s3 = 30 # NP
s1 = 40; s2 = 30; s3 = 60 # NP
s1 = 30; s2 = 40; s3 = 60 # NP

if s1 >= 35:
    if s2 >= 35:
      if s3 >= 35:
          print("P")
      else:
          print("NP")
    else:
        print("NP")
else:
    print("NP")


s1 = 40; s2 = 50; s3 = 60 # P
s1 = 40; s2 = 50; s3 = 30 # NP
s1 = 40; s2 = 30; s3 = 60 # NP
s1 = 30; s2 = 40; s3 = 60 # NP
flag = False

if s1 >= 35:
    if s2 >= 35:
      if s3 >= 35:
        flag = True

if (flag == True):
    print("P")
else:
    print("NP")
    

s1 = 40; s2 = 50; s3 = 60 # P
s1 = 40; s2 = 50; s3 = 30 # NP
s1 = 40; s2 = 30; s3 = 60 # NP
s1 = 30; s2 = 40; s3 = 60 # NP
t = 0

if s1 >= 35:
    t = t + 1
    
if s2 >= 35:
    t = t + 1

if s3 >= 35:
    t = t + 1

if (t == 3):
    print("P")
else:
    print("NP")
