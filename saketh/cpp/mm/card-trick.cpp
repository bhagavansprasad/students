#include<iostream>
using namespace std;	
int main()
{	
	int i=0;//i is for places
	int j=1;//j is for values
	int a[12],count=0;
	cout<<endl;
	for(i=0;i<=12;i++)//for assigning all values as 0 in the array;
	{  
		a[i]=0;
		cout<<a[i]<<",";
	}
	cout<<endl;
	cout<<endl;
	cout<<endl;
    a[13]={1,0,2,0,3,0,4,0,5,0,6,0,7,0};
	/*for(i=0;i<=12;i++)//for printing  after assigning  values of 1-7  in the array;
	{  
		cout<<a[i]<<",";
	}*/
	cout<<endl;
	count=0;
	for (i=0,j=8;j<=10,i<13;i++)//for assigning values of 8-10 in the array;
	{
		if(a[i]==0)
			count++;
		if(count=2)
		 {	
			a[i]=j;
            j=j+1;   
		 }     
	}
	for(i=0; i<=12 ; i++ )//for printing  after assigning  values of 8-10  in the array;
	{  
		cout<<a[i]<<",";
	}*/
}	
