a = [5, 1, 8, 9, 6]
n=5
for i in range(0,n):                                                                
    for j in range(i + 1, n):       
        if(a[i]>a[j]):                                                        
        	temp = a[i]                               
        	a[i] = a[j]                          
        	a[j] = temp
for i in range(0,n):
	print a[i],			 
