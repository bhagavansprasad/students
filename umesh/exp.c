#include<stdio.h>
int b[20];
int a[20];
int i=0;
char exp[i]; 
int j=0;
int k=0;
char ch='0';
main()
{
	char exp[100]="(1+2)";
	if(exp[i]!='\0')
	{
	int val=pas(exp[100]);
	printf("%d",val);
    }
}
	void pas(char *exp[])
	{
		for( ;exp[i]!=')';i++)
		{
			push(exp[i]);
		}
		for(  ;a[k]!='('; )
		{
			pop(a[k]);
		}
		calc(b[j]);
	}
	void push(char a[k])
	{
		a[k]=exp[i];
		i++;
		k++;
		printf("%d",a[k]);
	}
	void pop(char b[j])
	{
		k--;
		b[j]=a[k];
		j++;
	}
	calc(char b[j])
	{
		if(b[j] !='(')
		{
			while(b[j] >= '1' && b[j] <= '9')
			i{
				b[j] =b[j] - ch;
				j= j- 2;
			}
			j= j+1;
			switch(b[j])
			{
				case'+':a[k] = b[j+1 ]+b[j-1];
						k++;
						printf("%d"a[k]);
						break;
				case'-':a[k] =b[j+1] -b[j-1];
				         k++; 
						printf("%d",a[k]);
						break;
			}
		}
	}
	return(a[k]);
}
