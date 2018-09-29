#include "stdio.h"

typedef struct
{ 
	int a;
	short b;
} sFile;

int main()
{
	sFile sData ={0,0};
	int d=1000;
	short i=20;
	
	FILE* fp=fopen("test.txt", "wb");

	if(1!=fwrite(&d,sizeof(d),1,fp)) return 1;
	if(1!= fwrite(&i,sizeof(i),1,fp)) return 1;

fclose(fp);

	fp = fopen("MyFile.dat","rb");  
	
	if((fread(&sData,sizeof(sData),1,fp))!= 1)
	return 1;

fprintf(stdout,"%d",sData.a);
fclose(fp);

return 0;
}
