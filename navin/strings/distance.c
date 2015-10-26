#include<stdio.h>
struct distance
{
	int feet;
	float inches;
};

void add(struct distance d1,struct distance d2,struct distance *d3);

int main()
{
	struct distance dist1,dist2,dist3;

	dist1.feet=20;
	dist1.inches=32;
	dist2.feet=4;
	dist2.inches=34;

	add(dist1,dist2,&dist3);
	printf("sum of distance : %d feet - %f inches \n",dist3.feet,dist3.inches);
}

void add(struct distance d1,struct distance d2,struct distance *d3)
{
	d3->feet=d1.feet+d2.feet;
	d3->inches=d1.inches+d2.inches;
	if(d3->inches>12)
	{
		d3->inches=d3->inches-12;
		++d3->feet;
	}




}

