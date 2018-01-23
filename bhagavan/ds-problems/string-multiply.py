import logging
import sys

def str_sum(A, B):
	logging.debug("%s" % (sys._getframe().f_code.co_name))
	ssum = [] 
	result = "" 
	carry = 0

	alen = len(A)
	blen = len(B)

	maxlen = alen if alen > blen else blen

	logging.debug("\tA :{0}, B :{1}".format(A,  B))
	logging.debug("\talen :%d, blen :%d, maxlen :%d" % (alen, blen, maxlen))

	if (alen == 0):
		return (B)

	if (blen == 0):
		return (A)

	for i in range(maxlen):
		a = int(A[i]) if i < alen else 0 
		b = int(B[i]) if i < blen else 0 

		temp = str(a + b + carry)
		#result.append((str(temp))[-1])
		result = result + str(temp)[-1]
		#carry = (0, int(temp[0]))[len(temp) > 1]
		carry = int(temp[0]) if len(temp) > 1 else 0

	#result.append((str(carry))[-1]) if carry > 0 else ""
	result += str(carry)[-1] if carry > 0 else ""
	return (result)
		
def multiply_str_int(A, b):
	logging.debug("%s" % (sys._getframe().f_code.co_name))
	temp = "" 
	alen = len(A)
	carry = 0

	for i in range(alen-1, -1, -1):
		a = int(A[i])
		sprod = str((a * b)+carry)
		temp = temp + sprod[-1]
		carry = int(sprod[0]) if len(sprod) > 1 else 0 
		logging.debug("\ta :%d, b :%d, sprod :%s, temp :%s, carry :%d" % (a, b, sprod, temp, carry))
	
	#print ("temp :%s" % temp)
	temp = temp + (str(carry)[-1] if carry > 0 else "")
	#print ("temp :%s" % temp)

	return(temp)

def str_multiply(A, B):
	logging.debug("%s" % (sys._getframe().f_code.co_name))
	ssum = result = zero_pad = ""
	carry = 0
	logging.debug("\tA :{0}, B :{1}".format(A,  B))

	blen = len(B)

	for j in range(blen-1, -1, -1):
		b = int(B[j])

		result = multiply_str_int(A, b)
		result = zero_pad + result 
		ssum = str_sum(ssum, result)

		#print ("-------")
		#print ("A :", A, " B :", "result :%s, sum :%s" % (result, ssum)) 
		msg = "\tA : {0} B :{1}, ".format(A, B)
		msg = msg + "result :%s, sum :%s" % (result, ssum)
		logging.debug("%s", msg)
		#print ("-------")

		zero_pad = zero_pad  + "0"

	return ssum[::-1]


snumbers = [
	["2073", "8", "0173"],
	["9876", "89", "7886"],
	["9876", "789", "6777"],
	["9876", "789", "67701"],
	["7989", "9899", "68891"],
	["9999", "9999", "89991"]
]
mnumbers = [
			["1234",      "813",       "1003242"],
			["8976",      "9",         "80784"],
			["8976",      "99",        "888624"],
			["8976",      "999",       "8967024"],
			["8976",      "9999",      "89751024"],
			["1234",      "8",         "9872"],
			["1234",      "81",        "99954"],
			["1234",      "81356",     "100393304"],
			["123004",    "81356",     "10007113424"],
			["1",         "898765432", "898765432"],
			["898765432", "0",         "0"]
			]

def test_sum(nlist):
	for row in nlist:
		rsum = str_sum(row[0], row[1])
		print (row[0], row[1], row[2], rsum)

#logging.DEBUG, logging.INFO, logging.WARNING, logging.ERROR, logging.CRITICAL

def main():
	log_level = logging.INFO
	logging.basicConfig(level= log_level)

	logging.debug("%s" % (sys._getframe().f_code.co_name))

	#test_sum(snumbers)

	for tlist in mnumbers:
		product = str_multiply(tlist[0], tlist[1])
		product = "0" if int(product) == 0 else product
		logging.info("\tA :%-10s B :%-10s product :%12s expected :%-10s" % (tlist[0], tlist[1], product, tlist[2]))
		logging.debug("\n")

		assert(product == tlist[2])

if (__name__ == "__main__"):
	main()
