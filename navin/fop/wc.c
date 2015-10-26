#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>

int get_word_count(char *p)
{
	int x,cnt=0;

	for(x=0;p[x]!='\0';x++)
	{
		if(p[x]!=' ' && (p[x+1]==' ' ||p[x+1]=='\0') )
			cnt+=1;
		if()	
	
	}		

	return (cnt);
}

int get_line_count(char *p)
{
	int x, ln=0;

	for(x=0;p[x]!='\0';x++)
	{
		if(p[x]=='\n') 
			ln+=1;
	}		
	return (ln);
}


main()
{
	int fd,i,x,cnt=0,ln=0;
	int ccount, lcount, wcount;

	ccount=lcount=wcount = 0;

	char buff[10000];

	fd=open("1.txt",O_RDONLY);
	i = read(fd,buff,10000);

	ccount += i;

	buff[i] = '\0';

	wcount = get_word_count(buff);
	lcount = get_line_count(buff);


	printf("word count is %d\n", wcount);
	printf("line count is %d\n", lcount);
	printf("char count is %d\n", ccount);
	close(fd);
}



