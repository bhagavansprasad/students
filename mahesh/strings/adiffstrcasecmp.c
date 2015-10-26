#include<stdio.h>
int astrcmp (char*p1,char*p2); 
main()
{
	int rv;
	char s1[100]="aura networks";
	char s2[100]="apra Networks";
	rv=astrcmp(s1,s2);
	if(rv==0)
	printf("same\n");
else
	printf("nt same\n");
}
int astrcmp(char*p1,char*p2)
{
	int flag=0,i,d;
	for(i=0;p1[i]!='\0'&&p2[i]!='\0';i++)
	{
	if(p1[i]>=p2[i])
	
		d=p1[i]-p2[i];
	else if(p2[i]>p1[i])
		d=p2[i]-p1[i];

		if(d!=32&&d!=0)
		{
			flag=1;
			break;
		}
	}
	return (flag);
}

