#include <stdio.h>
#include <string.h>
int main()
{
	int i,n;
	char *X="Alice";
	n = strlen(X);
	printf("length = %d\n",n);
	//*X=X[n];
	//printf("%c on X\n", X[--n]);
	for(i=0;i<=n;i++)
	{
		printf("%s\t", X);
		X++;
	}
	printf("\n", X);
	return 0;
}
