#include <stdio.h>
#include<string.h>
char* astrcat (char *,char *);

main()
{
	char s[20]="guys";
	char d[20]="hello";
	
	printf("before\n");
	printf("----->source:%s\n",s);
	printf("----->destination:%s\n",d);

	astrcat(d,s);

	printf("after\n");
	printf("----->source:%s\n",s);
	printf("----->destination:%s\n",d);
}
char* astrcat (char *p1,char *p2)
{
	int j,i;
	j=strlen(p1);

	printf("%d\n",j);
	for(i=0;p1[j]=p2[i];i++,j++);
}	

