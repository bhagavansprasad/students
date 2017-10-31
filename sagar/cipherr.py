'''
n=input()
l=len(n)
k=int(input())
up=''
for i in range(0,l):
	if(n[i].isalpha()==True):
		if(n[i].islower()==True):
			up=ord(n[i])+k
			if(up>122):
				up=up-26	
		if(n[i].isupper()==True):
			up=ord(n[i])+k
			if(up>90):
				up=up-26
				
		print(chr(up),end="")
	else:
		print(n[i])
'''

n=input()
l=len(n)
k=int(input())
up=''
for i in range(0,l):
	if(n[i].isalpha()==True):
		if(n[i].islower()==True):
			up=ord(n[i])+k
			if(up>122):
				up=up-26	
		if(n[i].isupper()==True):
			up=ord(n[i])+k
			if(up>90):
				up=up-26
				
		print(chr(up),end="")
	elif(n[i].isnumeric()==True):
		up=n[i]+k
		if(up>9):
			up=up-10
		print(up,end="")
	else:
		print(n[i])
