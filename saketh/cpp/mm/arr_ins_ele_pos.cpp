#include<iostream>
#include<cstdlib>
using namespace std;
int insertion( int pa[10000],int val,int pla)
 {
	int n,i=0;
	cout<<"enter the length of the array"<<endl;
	cin>>n;
    cout<<"enter the elements"<<endl;
	for(i=0;i<=n;i++)
		cin>>pa[i];
	cout<<"enter value to be inserted"<<endl;
	cin>>val;
	cout<<"enter the place the value would be inserted into"<<endl;
	cin>>pla;
    cout<<"initial array is"<<endl;
	for(i=0;i<=n;i++)
		cout<<","<<pa[i];
	cout<<endl;
	for(i=n-1;i>=pla;i--)
		pa[i+1]=pa[i];
	pa[pla]=val;
    cout<<endl;  
    cout<<endl;  
    cout<<endl; 
    
	cout<<"after insertion is:";
	for(i=0;i<=n;i++)
		cout<<","<<pa[i];
  return 0;  
 }
 int main()
 {
	 int a[5],value=9,place=1;
	 int insertion(a,value,place);
 }	 


	

	

