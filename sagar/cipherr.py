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


n=input()
l=len(n)
k=int(input())
'''


def encrypt(n, k):
	l = len(n)
	up=''
	print(n, end=" ")
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
			up = int(n[i]) + k
			if(up >9):
				up=up-10
			print(up,end="")
		else:
			print(n[i])

	print ("")

def test_1_to_100():
	n = "AZaz190"
	k = 90

	for i in range(1, 100):
		print(i, end=" ")
		encrypt(n, i)

def test_with_multiple_string():
	test_strings = [ 
			[ "abcd", 3 ],
			[ "xyz", 2],
			[ "12abcd", 4 ],
			[ "12abcd", 4 ],
			[ "12abcd", 4 ],
			[ "12abcd", 4 ],
			[ "12abcd", 4 ],
			[ "12abcd", 4 ],
			[ "12abcd", 4 ],
			[ "12abcd", 4 ],
			[ "12abcd", 4 ],
			[ "12abcd", 4 ],
			[ "12abcd", 4 ],
			[ "12abcd", 4 ],
			[ "12abcd", 4 ],
			[ "12abcd", 4 ],
			[ "1234", 9 ],
			[ "1234", 6 ]
		]

	for string in test_strings:
		#print (string[0])
		print(string[1], end=" ")
		encrypt(string[0], string[1])

	

def main():
	#test_1_to_100():
	test_with_multiple_string()

if (__name__ == '__main__'):
	main()

