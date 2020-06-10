#include<iostream>
#include<cstdlib>
using namespace std ;
int insertion(int *a,int p , int ele)
{
	int i=0,n;
	cout<<"please enter the no of elements required elements"<<endl;
	cin>>n;

	cout<<"enter the elements"<<endl;
	for(i=0;i<n;i++)
		cin>>a[i];

	cout<< "enter the element to be inserted"<<endl;
	cin>>ele;

	cout<<"enter the position ( 0 to "<<n<<"):"<<endl;
	cin>>p;
	if(p>n)
	{
		cout<<"invalid position";
	}	  
	if(p<=n)
	{
		for(i=n-1;i>=p;i--)
		{
			a[i+1]=a[i];
		}
		a[p]=ele;
		n=n+1;
		cout<<"element after insertion are"<<endl;
		for(i=0;1<n;i++)
			cout<<","<<a[i];
	}
    return 0;
}  
	int main()
    int insertion( *arr,position ,element)

