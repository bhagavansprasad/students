#include <stdio.h>
char buff[5][100];
//char buff2[100];
int flag[5] = {0};
void* amalloc(int size);
void afree(void *p);
main()
{
	int i;
	char  *p1[2], *p2[2];
	for( i = 0; i <= 4; i++)
	{
		printf("buff address is : %u\n", buff[i]);
	}
	p1[0] = amalloc(100);
	printf("address of p1 : %u\n", p1[0]);
	p2[1] = amalloc(100);
	printf("address of p2 : %u\n", p2[1]);
	p2[0] = amalloc(100);
	printf("address of p2 : %u\n", p2[0]);
	p2[0] = amalloc(100);
	printf("address of p2 : %u\n", p2[0]);
	//afree(p2[0]);
	p1[1] = amalloc(100);
	printf("address of p1 : %u\n", p1[1]);
	afree(p2[0]);
	p1[1] = amalloc(100);
	printf("address of p1 : %u\n", p1[1]);

}
void *amalloc(int size)
{
	int i;
	for(i = 0; i <=4; i++)
	{
		if(flag[i] == 0)
		{
			flag[i] = 1;
			return (void *)buff[i];
		}
	}
	return NULL;
}
void afree(void *p)
{
	int i;
	for(i = 0; i <= 4; i++)
	{
		if(p == buff[i])
		{
			flag[i] = 0;
		}
	}
	printf("no memory\n");
}
