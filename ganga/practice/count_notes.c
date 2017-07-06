#include <stdio.h>

void main()
{
	int n = 1024, notes, choice=0;
	
	switch(choice)
	{
		case 0:
			notes = n/1000;
			printf("1000 :%d\n", notes);
			n = n % 1000;

		case 1:
			notes = n/500;
			printf("500 :%d\n", notes);
			n = n % 500;

		case 2:
			notes = n / 100;
			printf("100 :%d\n", notes);
			n = n % 100;

		case 3:
			notes = n / 50;;
			printf("50 :%d\n", notes);
			n = n % 50;

		case 4:
			notes = n / 20;
			printf("20 :%d\n", notes);
			n = n % 20;

		case 5:
			notes = n / 10;
			printf("10 :%d\n", notes);
			n = n % 10;

		case 6:
			notes = n / 5;
			printf("5 :%d\n", notes);
			n = n % 5;

		case 7:
			notes = n / 2;
			printf("2 :%d\n", notes);
			n = n % 2;

		case 8:
			notes = n / 1;
			printf("1 :%d\n", notes);

		default:printf("\n");
	}
}
