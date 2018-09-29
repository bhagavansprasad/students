#include <stdio.h>
void visit();
int main()
{
	int i = 0;
	{
		static int a  = 5;
		XYZ:;
		printf("%d\n", a);
		a++;
		i++;
	}
	visit();
	//printf("%d\n", a);//error: 'a' undeclared a is alive but not
	//visible(accessable)
	if(i<5)
		goto XYZ;
	return 0;
}

void visit()
{

}


/*o/p:
5
6
7
8
9*/
	
