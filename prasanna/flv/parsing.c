#include<stdio.h>
#include <stdlib.h>
#include "flv_header.h"

void parsing_db()
{
	FILE *fp;
	stud_db_1 rd_db1;
	stud_db_2 rd_db2;
	int version;
	fp = fopen("student_db.txt","rb");
	fread(&version,4,1,fp);
	printf("Version of file: %d\n",version);

	if(version == 1)
	{
		printf("Name     Age     Class\n");
		while(fread(&rd_db1,sizeof(rd_db1),1,fp)==1)
			printf("%s    %5d    %5d\n",rd_db1.name,rd_db1.age,rd_db1.class);
		fclose(fp);
	}
	else if(version == 2)
	{
		printf("Name      Age     Class     Grade     Marks \n");
		while(fread(&rd_db2,sizeof(rd_db2),1,fp)==1)
			printf("%s    %5d     %5d    %5c   %6d\n",rd_db2.name,rd_db2.age,rd_db2.class,rd_db2.grade,rd_db2.marks);
		fclose(fp);
	}
	else
	{
		printf("Incorrect version\n");
		fclose(fp);
	}
}


