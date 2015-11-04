#include <fcntl.h>
#define MAX 50
int power=1,sum;
int convert_binary(char rem)
{
	int i,mask=1;
	int bin[8];
	printf("\n");
	return 0;
}



main()
{

/*	printf("%d\n",n);
	int rem;
	int i=0;
	char buff[MAX]={n};
	while(i<4)
	{
		printf("%c\n",buff[i]);
		//n= n%10;
		//convert_binary(rem);
		i++;

	}*/





	int fd,n,m;
	fd = open("sixth.flv",O_RDONLY,0);
	char buff[100];
	int i;
	int mask=1;
	read(fd,buff,14);
	read(fd,buff,3);
	n=buff[0]+buff[1]+buff[2];

	printf("%d\n",n);
	printf("%d\n",buff[0]);
	printf("%d\n",buff[1]);
	printf("%d\n",buff[2]);
	
	unsigned int s=buff[2],s1=buff[1];

	for(i=0;i<8;i++)
	{
		n = s&(mask<<i);
		if(n>0)
		{
			if(power == 1)
			{
				sum = sum +power;
			}
			else
			{
				sum = sum+power;
			}
		}
	power=power*2;

	printf("n--%d\n",n);
	printf("sum--%d\n", power);
	//printf("sum--%d\n",mask<<i);
	}
	//printf("%d\n",s>>2);
	printf("%d\n", sum);


for(i=0;i<8;i++)
	{
		n = s1&(mask<<i);
		if(n>0)
		{
			sum = sum+power;
		}
	power=power*2;

	printf("n--%d\n",n);
	printf("sum--%d\n", power);
	//printf("sum--%d\n",mask<<i);
	}

	printf("%d\n", sum);

}
