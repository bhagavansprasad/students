#include "stdio.h"
#include "string.h"

struct employe
{
	char name[30];
	char design[30];
	int salery;
	int id_no;
};
main()
{
	struct employe employe_1;
	struct employe employe_2;

	strcpy(employe1 name "naresh");
	strcpy(employe_1 design "S.D");
	employe_1 id_no:123456;
	employe_1 mobile:9066645668;
	
	strcpy (employe_2 name "sunny");
    strcpy(employe_2 design "C.E.O");
	employe_2 id_no:100023;
	employe_2 obile:8143409176;

	   printf("employe_1 name:%s",employe name);
	   printf("employe_1 design:%s",employe design);
	   printf("employe_1 id_no:%d",id_no);
	   printf("employe_1 mobile:%d",mobile);

	   printf("employe_2 name:%s",employe name);
	   printf("employe_2 design:%s",employe design);
	   printf("employe_2 id_no:%d",id_no);
	   printf("employe_2 mobile:%d",mobile);


	   return 0;
}

