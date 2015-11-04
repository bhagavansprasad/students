#include <stdio.h>
enum e
{
mem1=2,
mem2=5,
mem3=9
}; 
struct s
{
enum e en;
enum e D;
};
main()
{
	struct s S;
	//int i=S.en;
	printf("%d\n%d\n",sizeof(struct s),sizeof(enum e));
}

