#include <stdio.h>

char strings1[10][100] = { 
	"Aura net",
	"Bangalore",
	"India cuntry",
	"India cuntry",
	"India cuntry",
	"India cuntry",
	"India cuntry",
	"India cuntry",
	"India cuntry"
};

char strings2[10][100] = { 
	"Aura net",
	"Bangalore",
	"India auntry",
	"India duntry",
	"India cuxtry",
	"Inpia cuntry",
	"Incia cuntry",
	"Inxia cuntry"
};


main()
{
	int retval = 0, i = 0;

	for (i = 0; i < 10; i++)
	{
		printf("%d. %s %s\n", i+1, strings1[i], strings2[i]);
		retval = astrcmp(strings1[i], strings2[i]);
		printf("retval :%d\n", retval);

		if (retval == 0)
			printf("Same\n");
		else
			printf("NOT Same\n");

	}

	return 0;


}
