#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
//int get_word(char [],int, char);

int pid[5] = {2461, 2455, 2467, 2449, 2478};

//int pid[3] ={2185,978 ,2167 };
main()
{
	char buff[2000];
	int i;
	int fd,retval,j=0;
	int k=0;
	char b[100];
	int c;
	int curent;
	int old=0;
	int new;
	int n=12; 
	int sum=0;
	char fname[100];
	int a=0;
	int d,m,l;
	int f[2][2]; 
	//fd=open("a.txt", O_RDONLY);

	//	fd=open("/proc/3273/stat", O_RDONLY);
	while(1)
	{ 
		l=0;
		for(d = 0;d < 3;d++)
		{ 
			m=0;
			sprintf(fname,"/proc/%d/stat",pid[d]);
			//printf("fname :%s\n",fname);
			fd=open(fname,O_RDONLY);
			//			printf("\n %d",fd);
			if (fd < 0)
			{
				perror("open failed");
				printf("\n %s",fname);
			}	
			i=0;
			retval = read(fd, buff, 1000);
			buff[retval]='\0';
			//				printf("buff :%s\n", buff);
			for(j=0;j<=12;j++)
			{
				for( ;buff[i]!=' ';i++);
				i++;
			}
			sum=0; 
			for(c=0;c<=3;c++)
			{
				for(k=0  ;buff[i]!=' ';i++) 
				{
					b[k]=(buff[i]);
					k++;
				}
				b[k]='\0';
				i++;
				//printf("%s\n",b);
				a=atoi(b);
				sum=sum+a;
				//		printf("\n %d",sum);
			} 
			//	printf("\n %d",f[l][2]);

			f[l][0]=pid[d]; 
			//	printf("\n %d",f[l][m]);

			//	f[l][1]=old;
			printf("%d\n",f[l][1]);
			//	old=f[l][1];
			m=m+1;
			//			printf("\n %d",old);
			f[l][2]=sum-f[l][1];
			//		   printf("\n %d",f[l][2]);
			//printf("%d\n",old);
			//	printf("%d\n",curent);
			//printf("%d\n",sum);
			//printf("-->Val :%d\n", atoi(b));
			//	lseek(fd, 0, SEEK_SET);
			f[l][1]=f[l][2];
			//		printf("\n %d",f[l][1]);
			a++;
			l++;
		}	
		sleep(1);

	}
	close(fd);
}
