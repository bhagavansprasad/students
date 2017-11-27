'''
lent=int(200)
wid=int(input())
hel=int(input())
if(wid<lent and hel<lent):
		print("upload Another")
if(wid==hel):
	print("Accepted")
else:
	print("Crop the Picture")
'''

L = int(input())
number = int(input())
data = []
for i in range(number):
	data = list(map(int,input().split()))
	W = data[0]
	H = data[1]
	if (W < L or H < L):
		print("UPLOAD ANOTHER")
	elif(W == H):
		print("ACCEPTED")
	else:
		print("CROP IT")
