#!/bin/python3
import sys

alist = []

def update_list(n, a, b, k):
    print(n, a, b, k)

    alist[a] += k

    if (b+1 <= n):
        alist[b+1] -= k

    '''
    for i in range (a-1, b):
        alist[i] += k
    '''



def create_new_list(n):
    global alist

    for i in range (0, n+1):
        alist.append(0)
    print (alist)



'''
5 3
1 2 100
2 5 100
3 4 100
'''

if __name__ == "__main__":
    sum = 0
    tmax = 0
    n = 5
    m = 3
    tdata = [
    [1, 2, 100],
    [2, 5, 100],
    [3, 4, 100]
    ]

    create_new_list(n)
    for i in range(m):
        update_list(n, tdata[i][0], tdata[i][1], tdata[i][2])
        print (alist)

    print (alist)

    for i in range (0, n+1):
        sum = sum + alist[i]
        print (sum)
        if (sum > tmax):
            tmax = sum
    print (tmax)


'''
if __name__ == "__main__":
    n, m = input().strip().split(' ')
    n, m = [int(n), int(m)]
    create_new_list(n)
    for a0 in range(m):
        a, b, k = input().strip().split(' ')
        a, b, k = [int(a), int(b), int(k)]
        update_list(n, a, b, k)
'''
