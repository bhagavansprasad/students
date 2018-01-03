x=[[12,7,3],[4,5,6],[8,9,0]]
y=[[5,8,1],[10,5,2],[7,8,9]]
result=[[0,0,0],[0,0,0],[0,0,0]]
for i in range(len(x)):
	 for j in range(len (y[0])):
	 	 for k in range(len(y)):
	 	 	 result [i][j]+=x[i][k]*y[k][j]
for r in result:
   print(r)
