alist = [3, 5, 8, 9, 4, 6, 9, 7, 6, 2, 1]
#alist = [6, 8, 7, 5, 9]
noe = len(alist)
print_head = 0

def left(i):
	return(A[(i*2) + 1])

def right(i):
	return(A[(i*2) + 2])

def parent(i):
	return(A[(i-1)/2])

def lefti(i, top):
	lindex = (i*2) + 1
	return (-1 if lindex > top else lindex)

def righti(i, top):
	rindex = (i*2) + 2
	return (-1 if rindex > top else rindex)

def parenti(i, top):
	pindex = (i-1)/2
	return (-1 if pindex < 0 else pindex)

def heapify1(A, top):
	pi = top
	while(pi > 0):
		pi = int(parenti(pi, top))	
		li = int(lefti(pi, top))
		ri = int(righti(pi, top))

		print("top :%d, pi :%d, ri :%d, li :%d" % (top, pi, ri, li))
		if ((pi >= 0 and ri <= top) and A[pi] > A[ri]): 
			t = A[pi]
			A[pi] = A[ri]
			A[ri] = t
		dump_list(A)

		if ((pi >= 0 and li <= top) and A[pi] > A[li]): 
			t = A[pi]
			A[pi] = A[li]
			A[li] = t
		dump_list(A)
	#dump_list(A)
	print ("")

def heapify(A, top):
	pi = top
	while(pi > 0):
		ci = pi
		pi = int(parenti(pi, top))	

		#print("top :%d, ci :%d, pi :%d" % (top, ci, pi))
		print ("%d:%d:%d" % (top, ci, pi)),
		#if ((pi >= 0 and idx <= top) and A[pi] > A[idx]): 
		if (A[pi] > A[ci]): 
			t = A[pi]
			A[pi] = A[ci]
			A[ci] = t
		dump_list(A)

	#dump_list(A)
	print ("")


def dump_list(alist):
	global print_head
	if (print_head == 0):
		print ("%5s" % " "),
		for i in range(0, len(alist)):
			print ("%-3d" % (i)),
		print_head = 1
		print ("")
		
	print ("%5s" % " "),
	for i in alist:
		print ("%-3d" % (i)),

	print ("")

def heap_sort(alist, top):
	i = top
	while (i >= 0):
		heapify(alist, i)
		i = i - 1

def main():
	dump_list(alist)
	print ("")
	heap_sort(alist, noe-1)
	dump_list(alist)
	

if (__name__ == "__main__"):
	main()

