fitness = ("skinny", "fat")[True]
print("Ali is ", fitness)

fitness = ("skinny", "fat")[False]
print("Ali is ", fitness)

A = "56"
print (A)
alen = len(A)

i = 0

a = (0, int(A[i]))[i < alen]
print (a)
i = i + 1

a = (0, int(A[i]))[i < alen]
print (a)
i = i + 1

'''
a = (0, int(A[i]))[i < alen]
print (a)
i = i + 1
'''
a = int(A[i]) if i < alen else 0 
print (a)

A = [10,20]
print (A)
print ("%{0} abce {1}".format(A, A))

print ("".join(str(A)))
