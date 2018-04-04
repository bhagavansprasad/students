#!/bin/python3

import sys

def get_glass_sum(row, col):
    sum = 0
    
    for i in range (col, col+3):
        #print ("(%d, %d)" % (ro))
        sum = sum + arr[row][i]
    sum = sum + arr[row+1][col+1]
    
    for i in range (col, col+3):
        sum = sum + arr[row+2][i]
    
    print (sum)
    return sum
    
def get_max_matrix_sum(arr):
    row_count = 6
    col_count = 6
    len = 6
    sum = 0
    flag = 0
    
    for i in range (0, len-2):
        for j in range(0, len-2):
            sum = get_glass_sum(i, j)
            if (flag == 0):
                max = sum
                flag = 1
            else:
                if (sum > max):
                    max = sum
    return max



arr = [
[1, 1, 1, 0, 0, 0, ],
[0, 1, 0, 0, 0, 0, ],
[1, 1, 1, 0, 0, 0, ],
[0, 0, 2, 4, 4, 0, ],
[0, 0, 0, 2, 0, 0, ],
[0, 0, 1, 2, 4, 0, ]
]
def main():
    print (get_max_matrix_sum(arr))

if (__name__ == "__main__"):
     main()
