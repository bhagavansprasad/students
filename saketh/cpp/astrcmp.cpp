#include<iostream>
#include<cstring> 
using namespace std;
int astrcmp( char *s1,  char *s2)
{	
	int i=0;
	for(i=0;s1[i]!='\0';i++)
	{ 
		if(s1[i]!=s2[i])
			break;
	}
	return (s1[i]-s2[i]);
}
int main()
{
	char a[]="saketh";
	char b[]="sakethram";
	int	t = astrcmp(a,b);
	cout<<"s1 : "<<a<<endl;
	cout<<"s2 : "<<b<<endl;

	if(t!=0)
		cout<<"the strings are not same";
	else
		cout<<"the strings are  same";

	cout<<endl;		
	return 0 ;

}
