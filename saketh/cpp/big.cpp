#include<iostream>
using namespace std;
int main()
{	
	//int a=10, b=34, c=23;
	int a=10, b=34, c=60;
	//int a=50, b=34, c=23;
	int largest, smallest, sec;															
	//cout<<"enter 3 numbers";
	//cin>>a>>b>>c;
	largest=a;
	smallest=a;
	if(b>largest)
		largest=b;
	if(c>largest)		
		largest=c;
	if(b<smallest)
		smallest=b;
	if(c<smallest)
		smallest=c;
	sec=(a+b+c)-(largest+smallest);
	cout<<"largest number is"<<largest<<endl;
	cout<<"smallst number is"<<smallest<<endl;
}
