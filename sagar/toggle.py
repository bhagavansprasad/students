n=input()
l=len(n)
s=[]

for i in range(0,l):
    if(n[i].islower()==True):
        m=n[i].upper()
        s.append(m)
    else:
        m=n[i].lower()
        s.append(m)
w=''.join(s)
print(w)
