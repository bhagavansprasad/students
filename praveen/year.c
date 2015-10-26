#include <stdio.h>
main(viod)
{
	int d = 02,m =05,y=2000;
	int flag = 1,isleap = 0;
	printf("the date is :%d/%d/%d",d,m,y);
	if(y%100 != 0 && y%4 == 0 || y%400)
		isleap = 1;
	if(y < 1850 ||y > 2050 || m<1 || m>12 || d < 1 || d>31)
		flag = 0;
	else if(m == 2)
	{
		if(d == 30 || d == 31 || (d == 29 && !isleap))
			flag = 0;
	}
	else if(m == 4 || m == 6 || m ==9 || m == 11)
	{
		if(d == 31)
			flag = 0;
	}
	if(flag == 0)
		printf("not a valid date \n");
	else
		printf("valid date \n");
		return 0;
}
