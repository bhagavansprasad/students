#include<iostream>
using namespace std;
int main()
{
	int b[5][5]= 
	{
		{ 1,2,3,4,5},
		{ 6,7,8,9,10},
		{11,12,13,14,15,},
		{16,17,18,19,20,},
		{21,22,23,24,25}
	};
	int i,n=3, r,c,sp=0,m=3;

	for(r=0,c=0 ;c<5;c++)
            cout<<b[r][c]<<"__";

	for(c=4,r=1; r<=3 ;r++)
		  cout<<b[r][4]; 
	
	for(r= 4 ; c>=1;c--)
	 cout<< b[r][c]<<endl;
	
	for(c=0,r=4; r>=1 ; r--)
		cout<<b[r][c]<<endl;
}		
