#include <stdio.h>

main()
{
	char dstr[5][15] = { "Aura Networks",
						 "bangalore",
						 "india"
				   	   };
	printf("-->dstr :%p\n", dstr);
	printf("-->dstr[1] :%p\n", dstr[1]);
	printf("-->&dstr :%p\n", &dstr);
	printf("-->dstr[1][1] :%c\n", dstr[1][1]);
	printf("-->&dstr[1][1] :%p\n", &dstr[1][1]);
	printf("-->dstr + 1 :%p\n", dstr + 1);
	printf("-->&dstr + 1 :%p\n", &dstr + 1);
	printf("-->*&dstr :%p\n", *&dstr);
}
