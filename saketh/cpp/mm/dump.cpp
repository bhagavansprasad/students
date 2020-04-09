#include<iostream>
using namespace std;
int main()
{
	int a[12],i=0,j=1,size=13,temp=0;
	for(i=0;i<=12;i++)
		cin>>a[i];
    for(i=3,j=8;i<=11,j<=10;i++,j++)
	{
	    if(a[i]==0)
			temp++;
			a[i]=j;
			temp=0;
			j++;
	}
	for(i=0;i<=12;i++)
	{
		cout<<a[i]<<",";
	}	
			
}


