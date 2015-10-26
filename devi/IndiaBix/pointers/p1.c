#include <stdio.h>

int main()
{
	char *s[] = {"black", "white", "pink", "voilet" };
	printf("s=%u\ts+1=%u\ts+2=%u\ts+3=%u\n",s,s+1,s+2,s+3);
	printf("\n values\n");
	printf("*s=%s\t*(s+1)=%s\t*(s+2)=%s\t*(s+3)=%s\n",*s,*(s+1),*(s+2),*(s+3));
	char **p[] = {s+3, s+2, s+1, s};
	printf("p=%u\tp+1=%u\tp+2=%u\tp+3=%u\n", p,p+1,p+2,p+3);
	printf("*p=%u\t*(p+1)=%u\t*(p+2)=%u\t*(p+3)=%u\n", *p,*(p+1),*(p+2),*(p+3));
	printf("p=%s\tp+1=%s\tp+2=%s\tp+3=%s\n", **p,**(p+1),**(p+2),**(p+3));
	char ***ptr;
	ptr = p;
	++ptr;
	printf("%s\n", **ptr+1);
	return 0;
}
