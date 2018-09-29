//auto vaar gets m/m at run time
//auto var default value is garbage
//scope is with in blk
//visibility is with in blk
#include <stdio.h>
int main()
{
int i = 0;
{
    XYZ:;// if u give xyz here u get o/p 20 20 20
	auto int a  = 20;
	//XYZ:;  if u give xyz here u get o/p 20 21 22
	printf("%d", a);
	a++;
	i++;
}
if(i<3)
goto XYZ;
return 0;
}
