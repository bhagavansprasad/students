#include<stdio.h>
#include<string.h>

char buff[30]="    10   20   30   40      50    ";
int cha_int(char*b,char deli)
{
	int i,j=0,temp;
	char name[30];
	for(i=0; ; i++)
	{
		if(b[i] != deli && b[i] != '\0')
		{
			name[j++]=b[i];
		}
		else
		{
			// name[j!]=0)                        
			name[j]='\0';
			printf("vallu--> =%d\n",atoi(name));
			j=0;
		}
		if(b[i]==deli)
		{ 
			for( ; b[i] == deli;i++);
			i--;
		}
		if(b[i]=='\0')
			break;



	}
}
int main(void)
{

	cha_int(buff,' ');

}	

