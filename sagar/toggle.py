'''
n=input()
l=len(n)
b=[]
for i in range(0,l):
	if(n[i].islower()==True):
		m=n[i].upper()
		b.append(m)
	if(n[i].isupper()==True):
		m=n[i].lower()
		b.append(m)
c=''.join(b)
print(c)
'''
import sys
a = list(sys.stdin.readline())
answer = ''
for elem in a:
	if elem.isupper():
		answer += elem.lower()
	else:
		answer += elem.upper()
print(answer)
