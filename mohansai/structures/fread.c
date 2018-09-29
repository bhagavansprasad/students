#include "stdio.h"
#include "stdlib.h"
struct emp
{
	char name[100];
	int age;
	int dob;
};

main()
{
	struct emp s1,s2,s3;

	FILE *fp,*fs;

	fp=fopen("samp.txt","r");
	
	if(fp==NULL)
	{
		perror("there id no content in the file");
		exit(1);
	}
	
	fread(&s1,sizeof(struct emp),1,fp);	
	printf("s1.name :- %s s1.age :- %d s1.dob :- %d \r\n", s1.name ,s1.age, s1.dob);
	
	fread(&s1,sizeof(struct emp),1,fp);	
	printf("s2.name :- %s s2.age :-%d s2.dob :- %d\r\n", s2.name, s2.age, s2.dob);
	
	fread(&s1,sizeof(struct emp),1,fp);	
	printf("s1.name :- %s s3.age :- %d s3.dob :- %d\r\n", s3.name, s3.age, s3.dob);
}

