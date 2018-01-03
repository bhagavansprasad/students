n=input()
k=int(input())
up=''
for i in n:
	up=ord(i)+k
print(chr(up),end=" ")
