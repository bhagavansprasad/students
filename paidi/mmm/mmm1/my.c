#include "mmm1.h"

void test1(void)
{
	char *p1, *p2, *p3,*p4;
	printf("\n:_____test1_________\n");
p1 = amalloc(320);
	p2 = amalloc(320);
	p3 = amalloc(320);
    p4 = amalloc(320);
	sleep(2);
	afree(p1);
	afree(p2);
	display_stats();
}
void test2(void)
{
	void *p1, *p2, *p3, *p4;
	printf(": ______test2_______\n");
	p1 = amalloc(30);
	p2 = amalloc(30);
	p3 = amalloc(30);
	p4 = amalloc(30);
	sleep(2);
	afree(p2);
	afree(p3);
	display_stats();
}
void test3(void)
{
	void *p1, *p2, *p3, *p4;

	printf(": ________test3________\n");
	p1 = amalloc(500);
	p2 = amalloc(400);
	p3 = amalloc(350);
	p4 = amalloc(250);
	display_stats();
	//afree(p1);
	//afree(p2);
    //afree(p3);
   //afree(p4);
//	display_stats();
	p1 = amalloc(150);
	p2 = amalloc(150);
	p3 = amalloc(150);
	p4 = amalloc(150);
	display_stats();
	afree(p1);
	afree(p2);
	display_stats();
}
int main()
{	
     //test1();
	// test2();
	//test3();
	//sleep(10);
	//display_stats();
	
	//sleep(1);
	 //test2();
	//display_stats();

	//sleep(2);
	//test3();
	//display_stats();

    char *p1 = amalloc(120);
	printf("p1 -- %p\n",p1);
	p1[150] = 'x';
	display_stats();
	afree(p1);
	//sleep(3);
	//memory_leak();
	display_stats();
}
