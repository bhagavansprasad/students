#include<stdio.h>
#include<fcntl.h>
#include<string.h>
main()
{

	int fd=0,i,j,k=0,t,u;
	char s[100],s1[100],b[100],c[100]="src=";
	fd=open("page.html",0,O_RDONLY);
	for(j=0; ;j++)
	{

		u=read( fd, s, 4);
		s[u]='\0';
		printf("u:%d\n",u);

		for(i=0;i<=3;i++)
		{
			while(s[i]==c[i] && s[i]!='\0')
			{
				k++;
				i++;
				printf("k:%d\t",k);
				printf("i:%d\t",i);
				if(k==4)
				{
					printf("if k:%d\n",k);
					do
					{
						t=read( fd, b, 1);
						b[t]='\0';
						printf("t:%d\n",t);
						strcat(s1,b);
						i++;
						if(b[0]==' ')
						{
							printf("%s\n",s1);
							printf("break i:%d\n",i);
							break;
						}
					}while(1);

				}
			}
		}
		if(k<4)
		{
			k=0;
			lseek(fd,-3,SEEK_CUR);
		}
		if(k>=4)
		{
			printf("break k:%d\n",k);
			break;
		}
	}

}








