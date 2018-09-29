#include<stdio.h>
#include<string.h>
main()
{
	char str[]="hello madam liril";
	int count;
	count=polindrum(str);
	printf("count is %d\n",count);
}
/*splitting variables*/

int polindrum(char *str)
{
	char a1[20],a2[20],a3[20];
	int i,c;
	static p;

	sscanf(str,"%s%s%s",a1,a2,a3);
	printf("a is %s\n",a1);
	printf("b is %s\n",a2);
	printf("b is %s\n",a3);
	
	p=polindrum_r_not(a1);
	printf("first p is %d\n",p);
	
	p=polindrum_r_not(a2);
	printf("p is %d\n",p);
	
	p=polindrum_r_not(a3);
	printf("p is %d\n",p);

	return(p) ;
}

/*polindrum r not*/



int polindrum_r_not(char *a)
{
	char c[20];
	int temp,i,j;
	static n=0;
	strcpy(c,a);
	for(i=0,j=strlen(a)-1;i<=j;i++,j--)
	{
		temp=a[i];
		a[i]=a[j];
		a[j]=temp;
	}
	printf("a is %s\n",a);
	printf("c is %s\n",c);

	if(strcmp(c,a)==0)
	{   
        n++;
		return(n);
	}	
	else 
	{
		return(0);
	}	

}


