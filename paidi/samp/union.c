#include <stdio.h>
main()
{
	union exam
	{
		int i;
		char ch [2];
	}
	 key ;

	key.i=512;
	printf("key.i=%d\n",key.i);
	printf("key.i=%d\n",key.ch[0]);
	printf("key.i=%d\n",key.ch[1]);
}
