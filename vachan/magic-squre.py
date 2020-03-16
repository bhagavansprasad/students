a=[
        [0,0,0,0,0], 
        [0,0,0,0,0],
        [0,0,0,0,0],
        [0,0,0,0,0],
        [0,0,0,0,0]
  ]
n=5
r=0
c=int(n/2)

for i in range(n):
    for j in range(n):
        print(f"%2d" % (a[i][j]), end=" ")
    print()

i=1

print()

while(i <= n*n):
    #print(f"r :{r}, c:{c}")
    a[r][c]=i

    r = r - 1
    c = c + 1

    if(c==n and r<0):
        r=r+2
        c=c-1

    if(r<0):
        r=n-1

    if(c>=n):
        c=0
        
    if(a[r][c]!=0):
        r=r+2
        c=c-1
    i=i+1

for i in range (n):
    for j in range(n):
        print(f"%2d" % (a[i][j]), end=" ")
    print()


