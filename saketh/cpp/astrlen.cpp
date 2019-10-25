#include<iostream>
#include<cstring> 
using namespace std;
int astrlen( char *s)

{	
	int i=0;
	for(i=0;s[i]!='\0';i++)
	{
	}	
	return i;
}
int main()
{	
	 int len=0;
	char a[]="saketh ram";
	len = astrlen(a);
	cout<<len<<endl;
}
