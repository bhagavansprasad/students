#include<stdio.h>
#include <fcntl.h>
#include "defs.h"

main()
{
	int rfd ,w = 0, i = 0;
	r s1[3];
	r1 s2[4];
	int index;
	rfd = open("student.db", O_RDONLY, 0777);
	w = read(rfd, &index, sizeof(index));
	if(index==1)
     {
	while(i < 3)
	{


			

			w = read(rfd, &s1[i], sizeof(r));
			printf("the students details is :\n");
			printf("name :%s\n", s1[i].name);
			printf("no   :%d\n", s1[i].no);
			printf("class:%d\n", s1[i].class);
			i++;
		}
	}
	if(index==2)
	{
    while(i<3)
		{

			w = read(rfd, &s2[i], sizeof(r1));
			printf("the students details is :\n");
			printf("name :%s\n", s2[i].name);
			printf("grade :%c\n", s2[i].grade);
			printf("marks   :%d\n", s2[i].marks);
			printf("no   :%d\n", s2[i].no);
			printf("class:%d\n", s2[i].class);
			i++;
		}


	}
	close(rfd);
}

