#include<stdio.h>
main()
{
	char buff[100]="how a   are  you a ";
	int i,w=0,c=0,n,fd1;
        fd1=open("rt.txt",O_RDONLY)
          
	for(i=0;buff[i]!='\0';  i++)
	{
         val=read(fd1,buff,10);
         
		if(buff[i]==' ')
			w=w+1;
		for( ;buff[i]==' ';i++);
		{
		}
		if(buff[i]>=65 && buff[i]<=122)
		{
			c=c+1; 
		}
		if(buff[i]=='\n')
		{
			n++;
		}  

	}
	printf("%d\n%d\n%d\n",w,c,n);
}
