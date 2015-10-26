#include<stdio.h>
#include<stdlib.h>
#include"flv_header.h"
/*	
stud_db_1 st[10]={{"Sunil",20,5},
					{"Anil",23,7},
					{"Prasan",25,12},
					{"Satish",23,11},
					{"",-1,-1}
				   };

*/
stud_db_2 st[10]={{"AAA",20,5,'A',89},
					{"BBB",23,7,'C',55},
					{"CCC",25,12,'B',65},
					{"DDD",23,11,'C',},
					{"",-1,-1,' ',-1}
				   };


void build_db()
{
	FILE *fp;
	int version = 2, i;
	char filename[20]="student_db.txt";

	fp = fopen(filename,"wb");
	
	fwrite(&version,sizeof(version),1,fp);
	for(i = 0; st[i].age != -1; i++)
		fwrite(&st[i],sizeof(st[i]),1,fp);
	
	fclose(fp);
}

main()
{
	build_db();
	parsing_db();
}


