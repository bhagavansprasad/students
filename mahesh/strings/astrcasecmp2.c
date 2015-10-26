#include <stdio.h>
int astrcasecmp(char *,char *);
char lwr(char );
main()
{
	int rv;
	char s1[16]="aura networks";
	char s2[16]="AURA network";
	rv=astrcasecmp(s1,s2);
	if(rv==0)
	printf("same\n");
	else 
	printf("not same\n");
}
int astrcasecmp(char *p1,char *p2)
{
	int i,rv;
	char p3,p4;
	for(i=0;p1[i]!='\0'&&p2[i]!='\0';i++)
	{
		p3=lwr(p1[i]);
		p4=lwr(p2[i]);
		if(p3!=p4)
		{
			rv =1;
			break;
		}
	}
	 if((p1[i]!='\0'&&p2[i]=='\0')||(p1[i]=='\0'&&p2[i]!='\0'))
  		rv =1;
	return(rv);

}
char lwr(char l)
{
	if(l>=65&&l<=90)
		l=l+32;
	return(l);
}
