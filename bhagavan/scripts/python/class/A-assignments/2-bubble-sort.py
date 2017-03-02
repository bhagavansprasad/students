data = [4, 8, 2, 9, 1] 
temp = 0

def my_bubble_sort(pdata):
    noe = len(data)
    i, j = 0, 0

    print "noe :", noe
    while(i < noe):
        j = i + 1
        while (j < noe):
            if (pdata[i] > pdata[j]):
                temp = pdata[i]
                pdata[i] = pdata[j]
                pdata[j] = temp
            j += 1

        i += 1


print ""
print "Before sorting list is :", data
my_bubble_sort(data)
print ""
print "After sorting list is  :", data
