#include<stdio.h>
main()
{
	char buff[100]="hi sunny\nhow are u\nwr r u";
	int ln=0;
	ln=alnc(buff);
	printf("no. of lines %d\n",ln);
    return 0;
}
int alnc(char *p)
{
	int i=0,ln=1;
	for(i=0;p[i]!='\0';i++)
	{
		if(p[i]=='\n')
		ln=ln++;
	}
	return ln;
}
