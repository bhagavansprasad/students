#include <stdio.h>

#include <string.h>

int main() 

{

	char str[100]="SRAVANI";

	int i, j, k, ch;

	for(i=0;str[i]!='\0';i++)

	{

		ch=str[i];

		for(j=i+1;str[j]!='\0';j++)

		{

			if(str[j]==ch)

			{

				for(k=j;str[k]!='\0';k++)

				{

					str[k]=str[k+1];

				}

			}

		}

	}

	printf("after removing duplicates:%s\n",str);

}
