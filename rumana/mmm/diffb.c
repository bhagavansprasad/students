#include<stdio.h>
//int flag[10]={0};
char *p1[3];
main()
{
	char *p,buff1[200],buff2[600],buff3[1500];
	int buff[3][2]={ 	
						{100,2},
						{200,3},
						{300,5}
					};
	int i,size=0;

	for(i=0;i<3;i++)
	{
		size=size+(buff[i][0]*buff[i][1]);
		
	}
	 printf("size is %d\n",size);
	

		
		p=malloc(size);
		printf("p1 is %u\n",p);
		
		p1[0]=p;
		printf("p1[0] is %u\n",p1[0]);
		
		p1[1]=&p[200];
		printf("p1[1] is %u\n",p1[1]);
		
		p1[2]=&p[800];
		printf("p1[2] is %u\n",p1[2]);

		

}
