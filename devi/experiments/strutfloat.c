#include <stdio.h>
struct s
{
	char name[20];
	float fl;
};
int main()
{
	struct s sf[3];
	int i;
	for(i=0;i<3;i++)
	{
		scanf("%s %f\n",sf[i].name,&sf[i].fl);
	}
	for(i=0;i<3;i++)
	{
		printf("%s %f\n",sf[i].name,sf[i].fl);
	}
}
