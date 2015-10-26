#include <stdio.h>
struct first
{
	int field id;
	int len;
	int fp(void *s,void *d,int len);
};

struct first data[128]={
							{1},
							{},
							{}
						};
