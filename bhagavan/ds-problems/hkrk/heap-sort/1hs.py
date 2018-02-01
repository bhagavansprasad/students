A = [8, 9, 6, 4, 3, 7, 9, 5]
#alist = [6, 8, 7, 5, 9]

noe = len(A)
top = noe-1
print_head = 0

def del_min():
	global top
	(A[0], A[top]) = (A[top], A[0])
	top = top - 1

def left(i):
	return(A[(i*2) + 1])

def right(i):
	return(A[(i*2) + 2])

def parent(i):
	return(A[(i-1)/2])

def lefti(i):
	lindex = (i*2) + 1
	return (-1 if lindex > top else lindex)

def righti(i):
	rindex = (i*2) + 2
	return (-1 if rindex > top else rindex)

def parenti(i):
	pindex = (i-1)/2
	return (-1 if pindex < 0 else pindex)

def heapify(i):
	while(i >= 0):
		li = lefti(i)
		ri = righti(i)
		pi = i

		#print("top :%d, ci :%d, pi :%d" % (top, ci, pi))
		#print ("%3d:%3d:%3d:%3d" % (top, pi, li, ri))

		if (li > 0 and A[pi] > A[li]): 
			(A[pi], A[li]) = (A[li], A[pi])

		if (ri > 0 and A[pi] > A[ri]): 
			(A[pi], A[ri]) = (A[ri], A[pi])

		i = parenti(i)
	#print ("")


def dump_list():
	global print_head

	if (print_head == 0):
		print ("%5s" % " "),
		for i in range(0, len(A)):
			print ("%-3d" % (i)),
		print ("")
		print ("-" * len(A)*5),
		print_head = 1
		print ("")
		
	print ("%5s" % " "),
	for i in A:
		print ("%-3d" % (i)),

	#print ("")

def temp(i):
	#print ()
	return

def heap_sort():
	i = 0
	global top

	while(i <= (noe-1)):
		#j = top - i
		j = top
		while (j >= 0):
			heapify(j)
			j = j - 1
		i = i + 1
		del_min()

def main():
	#print ("%3s:%3s:%3s:%3s" % ("top", "i", "li", "ri"))
	dump_list()
	print ("")
	heap_sort()
	dump_list()
	

if (__name__ == "__main__"):
	main()

