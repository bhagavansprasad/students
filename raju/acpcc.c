#include<stdio.h>
#include<fcntl.h>
main()
{
	char s[100]="",t[100]="";
	int r=0,w=0,l=10;
	int fd1=open("r.txt",O_RDONLY,0);
	int fd2=open("z.txt",O_CREAT|O_RDWR,0777);
	do
	{
		r=read(fd1,s,l);
		s[r]='\0';
		toggle(s,t);
		w=write(fd2,t,r);
	}while(r==l);
	close(fd1);
	close(fd2);
	printf("%s\n",t);
}
toggle(char s[],char d[])
{
	int i,capcount=0,smallcount=0;
	for(i=0;s[i]!=0;i++)		
	{
		if(s[i]>='A' && s[i]<='Z')
		{
			d[i]=s[i]+32;
			smallcount++;
		}
		if(s[i]>='a' && s[i]<='z')
		{
			d[i]=s[i]-32;
			capcount++;
		}
		if(s[i]>=32 && s[i]<=64)
		{
			d[i]=s[i];
		}
		if(s[i]=='\n')
		{
			d[i]='\n';
		}  
	}
	/*	printf("CapCount:%d\n",capcount);
		printf("SmallCount:%d\n",smallcount);*/

}	

