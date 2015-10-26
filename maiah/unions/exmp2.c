#include "stdio.h"
struct venky
{
	int mar;
	float per;
	char gd;
};
union siri
{
	int mar;
	float per;
	char gd;
};
main()
{
	struct venky v;
	v.mar=500;
	v.per=300;
	v.gd='A';
	printf("mar:%d\n per:%f\n gd:%c\n",v.mar,v.per,v.gd);
	printf("size of struct:%d\n",sizeof(struct venky));
	printf("add of mar:%u\n add of per:%u\n add of gd:%u\n",&v.mar,&v.per,&v.gd);
	
	union siri s;
	s.mar=300;
	s.per=300;
	s.gd='A';
	printf("mar:%d\n per:%f\n gd:%c\n",s.mar,s.per,s.gd);
	//printf("mar:%d\n gd:%c\n",s.mar,s.gd);
	printf("size of union:%d\n",sizeof(union siri));
	printf("add of mar:%u\n add of per:%u\n add of gd:%u\n",&s.mar,&s.per,&s.gd);
	//printf("add of mar:%u\n  add of gd:%u\n",&s.mar,&s.gd);

}

