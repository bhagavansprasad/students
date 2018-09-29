n = 29
i = 2
flag = 0

while (i < n):
	if (n % i == 0):
		flag = 1
		break
	i += 1
	

if flag == 1:
   print ("not prime")
else:
   print ("prime")

