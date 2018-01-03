
def prime(n):
	i = 0

	for i in range (2, n):

		if(n%i==0):
			break

	if(i==n-1):
		return(1)
	else:
		return(0)


n = 10
i = 0
R=n
r=0
for i in range(0, n):
		n=n+1
		if(prime(i)==1):
			print(i)
			r=r+1
		if(r==R):
			break
'''
numprimes = raw_input('How many primes to print?  ')
count = 0
potentialprime = 2

def primetest(potentialprime):
    divisor = 2
    while divisor <= potentialprime:
        if potentialprime == 2:
            return True
        elif potentialprime % divisor == 0:
            return False
            break
        while potentialprime % divisor != 0:
            if potentialprime - divisor > 1:
                divisor += 1
            else:
                return True

while count < int(numprimes):
    if primetest(potentialprime) == True:
        print 'Prime #' + str(count + 1), 'is', potentialprime
        count += 1
        potentialprime += 1
    else:
        potentialprime += 1
'''
