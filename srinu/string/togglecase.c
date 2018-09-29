#include<stdio.h>
#include<fcntl.h>
#include <string.h>
int main()
{
	int t;

	char str1[100]="hai = = SrAvAni";

	char str2[100]=" ";

	toggle_case(str2,str1);

	printf("%s\n",str2);

}

int toggle_case(char *s,char *d)

{
	int i;

	for(i=0;d[i]!='\0';i++)

	{

		if(d[i]<'A'||d[i]==' ')

		{
			s[i]=d[i];
		}

		else if(d[i]>=123&&d[i]<=127)

		{
			s[i]=d[i];
		}

		else if(d[i]>=32&&d[i]<=64)

		{
			s[i]=d[i];
		}

		else if(d[i]>=91&&d[i]<=96)

		{
			s[i]=d[i];
		}

		else if(d[i]>='A' && d[i]<='Z')

		{
			d[i]=d[i]+32;

			s[i]=d[i];
		}

		else

			if(d[i]>='a' && d[i]<='z')

			{
				d[i]=d[i]-32;

				s[i]=d[i];
			}
	}
	return  d[i];
}
