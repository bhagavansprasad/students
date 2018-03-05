'''
Input Format
------------
The first line contains N, the number of strings.
The next N lines each contain a string.
The N + 2nd line contains Q, the number of queries.
The following Q lines each contain a query string.

1 <= N <= 1000
1 <= Q <= 1000
1 <= Length of any string  <= 20

4
aba
baba
aba
xzxb
3
aba
xzxb
ab


2
1
0
'''

def get_string_count(lstrs, lqres):
    sl = len(lstrs)
    ql = len(lqres)
    print ("sl :%d, ql :%d" % (sl, ql))

    for i in range(0, ql):
        print(lstrs.count(lqres[i]))

lstrings = [
    "aba",
    "baba",
    "aba",
    "xzxb"
    ]

lqueries = [
    "aba",
    "xzxb", 
    "ab"
    ]

def main():
    '''
    lstrings = []
    lqueries = []
    n = int(input().strip())
    #print ("Number of strings :%d" % n)

    for i in range(0, n):
        s = input().strip()
        #print ("%d. Number of strings :%s" % (i, s))
        lstrings.append(s)

    q = int(input().strip())
    #print ("Number of quiries :%d" % q)

    for i in range(0, q):
        s = (input().strip())
        lqueries.append(s)
        #print ("%d. Number of strings :%s" % (i, s))
    '''
    get_string_count(lstrings, lqueries)

if (__name__ == "__main__"):
     main()
