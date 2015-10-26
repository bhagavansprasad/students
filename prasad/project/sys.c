#include"stdio.h"
#include"stdlib.h"


read_file()
{
    FILE *fp,*fp1,*fp2;
    int n,i,flag,pid;
    char c;
    char buff[10],buff1[256];
    fp=fopen("a.c","r");
    while(1)
    {

	i=0;
	flag=0;
	while((c=getc(fp))!=EOF)
	{
	    if((c==' ')||(c>='A'&&c<='Z'))
	    {
		flag = 1;
		break;
	    }
	    if(c=='\n')
		break;
	    buff[i]=c;
	    i++;
	}
	n=atoi(buff);
	if(c==EOF)
	    break;
	if(flag==0&&c!=' ')
	{
	    //fp1=fopen("/proc/n/stat","r");

	    sprintf(buff1,"/proc/%d/stat",n);
	    //  printf("%s \n",buff1);

	    if(n!=0)
		printf("%d \n",n);

	}
    }
    fclose(fp);
}
main()
{
    int i,fd;
    char buff[10];
    system("ps -A --no-headers -o pid>a.c");
    read_file();
}
