#include "stdio.h"
#include "stdlib.h"

struct flv
{
	char signature[3];
	unsigned char version ;
	unsigned char flag;
	unsigned int offset;
};


main()
{
	struct flv s1;

	FILE *fp;

	fp=fopen("sixthsense.flv","rb");
	if(fp==NULL)
	{
		perror("error i nm open a file");
		exit(1);
	}
	fread(&s1,sizeof(struct flv),1,fp);
	printf("signature:%s\t version: %d\tflag:%d\t offset:%d\t\n\r",s1.signature,s1.version,s1.flag,s1.offset);

}

