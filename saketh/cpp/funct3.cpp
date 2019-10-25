#include<iostream>
#include<cstring> 
using namespace std;
int astrcpy(char *d,char *s)
{	
	int i=0,a;
	for(i=0;s[i]!='\0';i++)
	{
		d[i]=s[i];
    }
	d[i]='\0';
	cout<<"s is :--"<<s<<endl;
	cout<<"d is :--"<<d<<endl;
	return 0;
}
int main()
{	
	char a[]="saketh ram";
	char s1[100];
	char s2[100];
	astrcpy(s1,a);

	cout<<" s1 is------:"<<s1<<endl;
    strcpy(s2,a);
	cout<<" s2 is------:"<<s2<<endl;
}
