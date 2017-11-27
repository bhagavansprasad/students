strn='All-convoYs-9-be:Alert1'
n=int(input())
answer=[]
for i in strn:
	a=ord(i)
	if(65<=a<=90 or 97<=a<=122):
		
		answer.append(a)
b=''.join(answer)
print(b)
