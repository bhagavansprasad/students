#include <stdio.h>
struct data1
{
	int a,b;
	char sc1,sc2,sc3,sc4;
};
union data3
{
		struct data1 d1;
};
struct data2
{
	int c;
	union data3 d3;
};
struct data2 d2;
void f1(int,int);
void f2(int,char);
void f3(char,char);
void f4(char,int,char);
void send_data(struct data2);
main()
{		
	int a1=10,b1=20;
	char c1='a',c2='b',c3='c',c4='d';
	f1(a1,b1);
	f2(a1,c1);
	f3(c1,c2);
	f4(c3,b1,c4);
}
void f1(int a1 , int b1)
{
//union data2 d2;
	d2.c=1;
	d2.d3.d1.a=a1;
	d2.d3.d1.b=b1;
	send_data(d2);
}
void f2(int a1 , char c1)
{
//union data2 d2;
	d2.c=2;
	d2.d3.d1.a=a1;
	d2.d3.d1.sc1=c1;
	send_data(d2);
}
void f3(char c1 , char c2)
{
//union data2 d2;
	d2.c=3;
	d2.d3.d1.sc1=c1;
	d2.d3.d1.sc2=c2;
	send_data(d2);
}
void f4(char c3, int a1 , char c4)
{
//union data2 d2;
	d2.c=4;
	d2.d3.d1.a=a1;
	d2.d3.d1.sc3=c3;
	d2.d3.d1.sc4=c4;
	send_data(d2);
}
void send_data(struct data2 d)
{
	switch(d.c)
	{
		case 1:
			printf("a=%d b=%d\n",d.d3.d1.a,d.d3.d1.b);
			break;
		case 2:
			printf("a=%d sc1=%c\n",d.d3.d1.a,d.d3.d1.sc1);
			break;
		case 3:
			printf("sc1=%c sc2=%c\n",d.d3.d1.sc1,d.d3.d1.sc2);
			break;
		case 4:
			printf("a=%d sc3=%c sc4=%c\n",d.d3.d1.a,d.d3.d1.sc3,d.d3.d1.sc4);
			break;		
		default:
			printf("undefined\n");
	}
}
