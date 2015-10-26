#include "structure.h"

int main()
{
	int rfd = 1,r = 1,version,n =3, j = 0;
	record1 s1[3];
	record2 s2[3];

	rfd = open("student2.db", O_RDONLY, 0777);

	if(rfd < 0)
	{
		printf("open rfd and errno = %d   %d\n",rfd,errno);
		perror("open failed because ");
	}

	printf("open is successful \n");
	r = read(rfd, &version, sizeof(version));

	if(version == 1)
	{
		printf("version number  == %d\n",version);
		while(j < n)
		{
			r = read(rfd,&s1[j],sizeof(record1));

			if( r < 0)
			{
				printf("read retval and errno = %d   %d\n",r,errno);
				perror("reading is failed because ");
			}
			printf("%d STUDENT DETAILS IN STRUCTURE 1 ------------->\n",j+1);
			printf("NAME  = %s\n",s1[j].name);
			printf("AGE   = %d\n",s1[j].age);
			printf("CLASS = %d\n",s1[j].class);
			j++;
		}
		close(rfd);

	}
	if(version == 2)
	{
		printf("version number == %d\n",version);

		while(j < n)
		{
			r = read(rfd,&s2[j],sizeof(record2));

			if( r < 0)
			{
				printf("read retval and errno = %d   %d\n",r,errno);
				perror("reading is failed because ");
			}
			printf("%d STUDENT DETAILS IN STRUCTURE 2 ------------->\n",j+1);
			printf("NAME  = %s\n",s2[j].name);
			printf("GRADE = %c\n",s2[j].grade);
			printf("AGE   = %d\n",s2[j].age);
			printf("MARKS = %d\n",s2[j].marks);
			printf("CLASS = %d\n",s2[j].class);
			j++;
		}

		close(rfd);
	}
}
