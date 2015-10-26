#include "structure.h"

int main()
{
	int rfd = 0, w = 0;
	int version = 1, j = 0, n = 3;
	record1 s1[3] = {{"kiran", 20, 10},{"pradeep", 20, 10},{"pavan", 25, 10}};

	record2 s2[3] = {{"siva", 65, 90, 20, 03},{"kiran", 65, 88, 20,
		03},{"naresh", 65, 90, 20, 03}};

	/*	strcpy(s1.name, "kiran");
		s1.age = 20;
		s1.class = 10;

		strcpy(s2.name, "rajini");
		s2.grade = 65;
		s2.marks = 90;
		s2.age = 21;
		s2.class = 10; */

	rfd = open("student2.db", O_CREAT|O_WRONLY, 0777);
	if(rfd < 0)
	{
		printf("open fd and errno = %d  %d \n",rfd , errno);
		perror("creating a file is failed because ");
	}
	if(version == 1)
	{
		w = write(rfd, &version, sizeof(version));
		while(j < n)
		{
			w = write(rfd, &s1[j], sizeof(record1));
			j++;
		}
	}
	else if(version == 2)
	{
		w = write(rfd, &version, sizeof(version));
		while(j < n)
		{
			w = write(rfd, &s2[j], sizeof(record2));
			j++;
		}
	}
	close(rfd);
}
