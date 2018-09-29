#include <stdio.h>
main()
{
	char dstr[5][15] = 
						{
						"Aura Networks",
						"Marthahalli",
						"Bangalore",
						"karnataka",
						"India"
						};
	int i,j;
	printf("dstr = %u and val = %s\n", dstr, dstr);
	printf("dstr + 1 = %u and val = %s\n",  dstr + 1, dstr + 1);
	printf("dstr + 2 = %u and val = %s\n",  dstr + 2, dstr + 2);
	printf("dstr + 3 = %u and val = %s\n",  dstr + 3, dstr + 3);
	printf("dstr + 4 = %u and val = %s\n",  dstr + 4, dstr + 4);
	printf(" the addr of dstr is %u\n",&dstr);
	printf("&dstr +1 = %u and val = %s\n", &dstr+1, &dstr+1);
	printf("dstr[1] = %u and val = %s\n",dstr[1], dstr[1]);
	printf("dstr[1][1] = %u and val = %c\n", dstr[1][1], dstr[1][1]);
	printf("&dstr[1][1] = %u and val = %s\n", &dstr[1][1], &dstr[1][1]);
	printf("*&dstr = %u and val = %s\n", *&dstr, *&dstr);
	printf("**&dstr = %u\n", **&dstr);
	printf("***&dstr = %c\n",***&dstr);
	/*printf("print each letter of array in index 0\n");
	j=0;
	for (i=0; i<15;i++)
	{
		printf("dstr[%d][%d] = %c",j,i,dstr[j][i]);
	}*/
}
