#include <stdio.h>
main()
{
	int d=31,m=8,y=2015,f,h,fh,day,j;
	j=d;
	switch(m-1)
	{
		case 11:j=j+30;
		case 10:j=j+31;
		case 9:j=j+30;
		case 8:j=j+31;
		case 7:j=j+31;
		case 6:j=j+30;
		case 5:j=j+31;
		case 4:j=j+30;
		case 3:j=j+31;
		case 2:j=j+28;
		case 1:j=j+31;
	}
	if(y%100!=0 && y%4==0|| y%400==0)
		if(m>2)
		j=j+1;
		f=(y-1)/4;
		h=(y-1)/100;
		fh=(y-1)/400;
		day=(y+j+f-h+fh)%7;
		switch(day)
		{
			case 0:printf("saturday\n");break;
			case 1:printf("sunday\n");break;
			case 2:printf("monday\n");break;
			case 3:printf("tuesday\n");break;
			case 4:printf("wenesday\n");break;
			case 5:printf("thursday\n");break;
			case 6:printf("friday\n");break;
		}
}
