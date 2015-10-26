#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	int fd1=0,fd2=0,i=0,j,k=0,l=0,retval,v;
	char *substr_ptr = NULL;
	char substr[100]= "src=", d[100]="You are left with only";
	char string[100000], url[100],s2[100],fil[100]="o.txt";
	char cmd[1000] = " ";
	//fd3 = open("o.txt", O_CREAT|O_RDWR, 0777);

	fd1 = open("page.html", 0, O_RDONLY);
	retval=read(fd1, string, 10000);
	string[retval]='\0';
	printf("read retval %d\n", retval);

	substr_ptr = astrstr(string, substr);
	if (substr_ptr == NULL)
	{
		printf("substring :%d, not found...exiting\n");
		exit(1);
	}

	copy_url(url, substr_ptr + strlen(substr), '"', ' ');

#if 0
	for(i=0;s[i]!='\0';i++)
	{
		while(s[i]==c[k] && s[i]!='\0' && s[i]!='\n' && k<4)
		{
			k++;
			i++;
			if(k==4)
			{
			//	lseek(fd1, i-retval, SEEK_END);

				for( ;s[i]!=' ';i++,j++)
				{
					url[j]=s[i];
				}   
			}
		}

		if(k<4)
		{ 
			k=0;
		}
		if(k>=4)
		{
			printf("break k:%d\n",k);
			break;
		} 

	}
#endif
	printf("url :%s\n", url);
	sprintf(cmd, "%s %s -O %s", "wget", url, fil);
	printf("cmd :%s\n", cmd);

	system(cmd);

	fd2=open("o.txt",0,O_RDONLY);
	v=read(fd2,s,100000);
	s[v]='\0';
	printf("v:%d\n",v);
	for(i=0;s[i]!='\0';i++)
	{

		while(s[i]==d[l] && s[i]!='\0' && s[i]!='\n' && l<22)
		{
			l++;
			i++;

			if(l==22)
			{
		//		lseek(fd2,i-v,SEEK_END);
				for( ;s[i-1]!='>';i++);
				for(j=0;s[i]!='<';i++,j++)
				{
					s2[j]=s[i];
				}   
			}  

		}

		if(l<22)
		{ 
			l=0;
		}
		if(l>=22)
			break;

	}
	printf("S2:%s\n",s2);	

	return 0;
}	   

char *strstr(const char *haystack, const char *needle)
{

}

int copy_url(char *url, char *source, char sch, char ech)
{
}
