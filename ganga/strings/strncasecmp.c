#include<stdio.h>
#include<string.h>
void main()
{
	int flag;
	char buff1[100]="AURA nET";
	char buff2[100]="aura Net";
	flag= astrncasecmp(buff1,buff2);
	if(flag==0)
		printf("same");
	else
		printf("not same");
}

int astrncasecmp(char*p1,char*p2)
{
	int flag=0,i=0,d=0,n=5;
	for ( i=0; i<n && p1[i]!='\0' && p2[i]!='\0' ;i++ )
	{
		if(p1[i]>=p2[i])
			d=p1[i]-p2[i];
		else if(p2[i]>p1[i])
			d=p2[i]-p1[i];
		if(d=32  && d!='\0')
		{
			flag=1;
			break;
		}

	}
	return (flag);
}

