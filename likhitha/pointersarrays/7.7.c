#include <stdio.h>
main()
{
char a[5][15]={ "Aura Networks",
				"Bangalore",
				"India"};

printf("%p\n",a);
printf("%p\n",a+1);
printf("%p\n",a[1]);
printf("%p\n",a[1][1]);
}
