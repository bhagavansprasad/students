#include<iostream>
#include<cstring> 
using namespace std;
int astrncmp( char s1[],  char s2[], int n)
{	
	int i=0;
	for(i=0;s1[i]!='\0'&& i<=n-1;i++)
	{ 

		if(s1[i]!=s2[i])
			break;
	}
	return (s1[i]-s2[i]);
}
int main()
{
	char a[]="sakethRAM";
	char b[]="sakethram";
	int n=7;
	int	t = astrncmp(a,b,n);
	cout<<"s1 : "<<a<<endl;
	cout<<"s2 : "<<b<<endl;
	cout<<"n : "<<n<<endl;

	if(t!=0)
		cout<<"the strings are not same";
	else
		cout<<"the strings are  same";

	cout<<endl;		
	return 0 ;

}
