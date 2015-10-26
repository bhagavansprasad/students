#include<stdio.h>
#include<string.h>

char atolower(char a);



/*main()
{
	char str[100]="        Madam      121   level";
	int i,j,k,palin=0;

	for(i=0;str[i]!='\0';i++)
	{
		for(  ;str[i]==' ' && str[i] != '\0'; i++);

		j = i;

		for(  ; str[i] != ' ' && str[i] != '\0'; i++);

		k = i-1;

		for(  ;atolower(str[j])==atolower(str[k]);j++,k--)
		{
			if(j>=k)
			{
				palin++;
				break;
			}
		}
	}
	
	printf("String:%s\n",str);
	printf("No. of Palindromes:%d\n",palin);

}*/
main()
{
	char str[100]="   Madam,    speaks     'malayalam'",buff[100];
	int i,j,k,palin=0;


	for(i=0;str[i]!='\0';i++)
	{
		for(  ;str[i]==' ';i++);


		for(k=0  ;str[i]!=' ' && str[i]!='\0';i++,k++)
		{
		
			
			if((str[i]>=48 && str[i]<=57) || (str[i]>=65 && str[i]<=90) || (str[i]>=97 &&
			str[i]<=122))
			{


				buff[k]=str[i];

			}
			else
				break;
			
			
	
		}	


		for(j=0  ; atolower(buff[j])==atolower(buff[k-1]);j++,k--)
		{
			if(j>=k)
			{
				palin++;
				break;

			}
		}	
	}
	printf("String:%s\n",str);
	printf("No. of Palindromes:%d\n",palin);



}






char atolower(char a)
{
	

	if(a>='A' && a<='Z')
	{
		a=a+32;
	}

	return a;
}	

