#include <stdio.h>
union std
{
	int a;
	char b[4];
};

int main()
{
	union std s1 = {300};

	/*int i;
	printf("s1.a = %d", s1.a);
	for(i=0;i<4;i++)
	printf("\ns1.b[%d] val = %d s1.b[%d]=%u",i, s1.b[i],i,&s1.b[i]);

	//o/p : 44 1 0 0
	*/

	/*printf("\naddr = %u and val is %d",&s1.a,(char)s1.a);
	printf("\nadr is %u and val is %d",(char*)(&s1.a)+1,(char)*((char*)(&s1.a)+1));
	printf("\nadr is %u and val is %d",(char*)(&s1.a)+2,(char)*((char*)(&s1.a)+2));
	printf("\nadr is %u and val is %d",(char*)(&s1.a)+3,(char)*((char*)(&s1.a)+3));
	
	o/p: 44 1 0 0

	*/
	/* char ch;
	ch = (char)s1.a;
	printf("\nch val is %d",ch);
	ch =(char) *((char*)((&s1.a)+1)-1);
	printf("\nch val is %d",ch);
	ch =(char) *((char*)((&s1.a)+1)-2);
	printf("\nch val is %d",ch);
	ch =(char) *((char*)((&s1.a)+1)-3);
	printf("\nch val is %d",ch);
	ch =(char) *((char*)((&s1.a)+1)-4);
	printf("\nch val is %d",ch);

	o/p: 0 0 1 44
	*/


}
