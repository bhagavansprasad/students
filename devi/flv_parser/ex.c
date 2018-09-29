#include <stdio.h>
enum typ{sun=4,
mon=1,
tue=8,
wed=9,
thurs,
fri,
sat
};


main()
{
	enum typ days;
	days  = sun;
	int i;

	//for(i=0;i<7;i++)
	printf("%d\n",days[sun]);

}
