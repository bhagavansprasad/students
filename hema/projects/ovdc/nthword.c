#include <stdio.h>
#include "defs.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int get_nth_word(char *src_buff, char *dst_buff,int n)
{
	int i = 0,j=0, wcount=0;

	for(i=0;src_buff[i]!='\0';i++)
	{
		while(src_buff[i]==' ' )
			i++;

		if(src_buff[i]!=' '&&src_buff[i]!='\0')
			wcount++;

		while(src_buff[i]!=' ' && src_buff[i]!='\0')
			i++;

		if(wcount==n-1)
		{
			while(src_buff[i] == ' ')
				i++;
			for(j = 0;src_buff[i]!=' ';i++,j++)
			{
				dst_buff[j] = src_buff[i];
			}
			dst_buff[j] = '\0';
		}
	}
}

