#include<stdio.h>
main()
{
	int km=300;
	float m,ft,in,cm;
	m=km*1000;
	ft=km*3280.8;
	in=km*39370.08;
	cm=km*100000;
	printf("value m=%f\n",m);
	printf("value ft=%f\n",ft);
	printf("value in=%f\n",in);
	printf("value cm=%f\n",cm);
}
