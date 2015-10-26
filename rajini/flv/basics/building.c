#include<stdio.h>
#include "fcntl.h"
#include "string.h"
#include "defs.h"
#include <errno.h>

main()
{
	int wfd,i = 0;
	int retval = 0;
	int index=2;


	r s1[3]={{"rajini",405,17},
		{"kanth",406,16},
		{"reddy",407,15}};


	r1 s2[5]={ {"ram",'A',850,405,17},
		{"rahim",'B',950,406,17},
		{"robot",'C',900,407,17}};



	wfd = open("student.db",O_CREAT|O_RDWR,0777);
	if(wfd < 0)
	{
		printf(" return value of wfd%d errno%d\n",wfd,errno);
		perror("opening is failed because");
	}
	else 
		printf("file is created  successfully\n");


	/*	strcpy(s1.name, "rajini kanth");
		s1.no = 405;
		s1.class = 17;
	 */

	retval = write(wfd, &index, sizeof(index));

	if(index==1)
	{
		while(i<3)
		{
			retval = write(wfd, &s1[i], sizeof(r));
			printf("size of structure1 %d \n", sizeof(r));
			printf("retval :%d\n ", retval);
			i++;
		}
	}
	else if(index==2)
	
		while(i<5)
		{
			retval = write(wfd, &s2[i], sizeof(r1));
			printf("size of structure2 %d \n", sizeof(r1));
			printf("retval :%d\n ", retval);
			i++;
		}
		

	close(wfd);
} 
