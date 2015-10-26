#include <stdio.h>
main()
{
	int i,num,count=0,sum=0;
	for(num=1; num<=100; num++)
	{
	    count=0;
		for(i=2;i<num;i++)
		{
			if(num%i==0)
			{
				count++;
				break;
			}
		}
		if(count==0&&num!=1)
		printf("%d\n",num);
		    //sum=sum+num;
	}
			//printf("%d\n",sum);
	return 0;
}
