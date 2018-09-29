#!/bin/python3
import sys

data = []
alist = []
def populate_data(file_data):
    global data
    fd = open(file_data)
    data += fd.readlines()
    #print (data)
    
def add_sum(a, b, tsum):
    global alist
    alist[a]= alist[p] + sum;

    if((b+1) <= N) 
        arr[q+1]-=sum;
    
def add_sum_to_elements(k):
    for i in range(1, k+2):
        a, b, tsum = data[i].split()
        add_sum(int(a), int(b), int(tsum))

def main():
    populate_data("input.txt")
    m, k = data[0].split()  
    print (m, k)
    alist = [0 for i in range(int(m))]
    #print (len(alist))
    add_sum_to_elements(k)

if(__name__ == "__main__"):
    main()

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
