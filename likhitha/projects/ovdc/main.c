#include <stdio.h>
#include<fcntl.h>
#include"string.h"

typedef struct ovdc_giffs
{
	int pid;
	int giffs;
}ovdc_data;


main()
{
	int pid[100]={1637,1685,1730,1775,1820};
	int giffs ,i , n=5 ,retval;
	printf(" ovd pid==%d\n",getpid());
	ovdc_data data;
	while(1)
	{
		for(i=0 ; i<n ;i++)
		{
			giffs=get_giffs_pid(pid[i]);
			if(giffs!=-1)
				send_giffs(pid[i],giffs);
		}
		data.pid=-1;
		data.giffs=-1;
		retval = write(&data, sizeof(data));
	}
	sleep(1);
}
int send_giffs(int pid, int giffs)
{
	int retval,i;
	ovdc_data data;		
	data.pid = pid;
	data.giffs = giffs;
	retval = write(&data, sizeof(data));

	if(retval >= 0)
	{
		printf("writing file is failed");
		return -1;
	} 

}

int get_giffs_pid(int pid)
{
	int fd , words = 0, retval=0 , x, i = 0, j = 0, value = 0, sum = 0 , p=0, q=0, diff=0,len=1024;
	char buff[1024];
	char temp[100] = "";

	sprintf(temp,"/proc/%d/stat",pid);
	fd = open(temp,O_RDONLY);

	if( fd < 0)
	{
		printf( "open failure\n");
		return;
	}

	retval = read(fd , buff, len);
	retval[buff] = '\0';
	printf("%s", buff);
	words = 0;
	//printf("%s\n", pbuff); 

	for( ; words != 13 && buff[i] != '\0'; i++) //getting 14th word
	{
		if (buff[i] == ' ')
			words++;
	}				
	//printf("i     :%d\n", i); 
	//printf("words :%d\n", words); 
	//printf("%s\n", &pbuff[i]); 

	sum = 0;
	for(words = 0 ; words < 4; words++)
	{
		for( ; buff[i] != ' '; i++, j++)
			temp[j] = buff[i];
		temp[j] = '\0';
		i++;
		value =(int) atoi(temp); //converting ascii to integer
		printf("value :%d\n", value);
		sum = sum + value;
		//	i++;	
		j = 0;

	}
	printf("sum=%d\n",sum);

	p=sum;
	diff=p-q;
	printf("diff=%d\n\n",diff);
	q=p;

	sleep(2);
	return sum;
	close(fd);
}

/*main()
  {
  get_giffs(data);
  }*/

