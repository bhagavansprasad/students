n=5
a = [[0 for i in range(n)] for j in range(n)]
r = 0
c = int(n/2)

for i in range(n):
    for j in range(n):
        print(f"%2d" % (a[i][j]), end=" ")
    print()

i=1

print()


for i in range (1,n*n+1):
    #print(f"r :{r}, c:{c}")
    a[r][c]=i

    r = r - 1
    c = c + 1

    if (r < 0 and c > n-1):
        r=r+2
        c=c-1

    if (r < 0):
        r=n-1

    if (c > n-1):
        c = 0

    if(a[r][c]!=0):
        r=r+2
        c=c-1

for i in range (n):
    for j in range(n):
        print(f"%2d" % (a[i][j]), end=" ")
    print()


