#include<stdio.h>
int main(void)
{
	int d,m,y;
	char *months[]={"january", "february", "march", "april", "may", "june",
	"july", "august", "sepember", "october", "november", "december"};
printf("enter date  (dd/mm/yyyy) : ");
scanf("%d %d %d",&d,&m,&y);
printf("%d %s %d\n",d,months[m-1],y);
return 0;
}
