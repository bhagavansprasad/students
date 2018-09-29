#include <stdio.h>

char data[1024] ="1734 (a.out) R 1555 1734 1555 34817 1734 4210688 75 0 0 0 951 3464 0 0 20 0 1 0 127576 2080768 136 4294967295 134512640 134514140 3213698384 3213696648 3078016332 0 0 0 0 0 0 0 17 1 0 0 0 0 0 134520584 134520868 163672064 3213701539 3213701545 3213701545 3213705204 0";

int get_giffs(char *pbuff)
{
	int j = 0, i = 0, c = 0, value = 0, sum = 0 , l;
	char temp[100];

	for(l=0 ; l<2 ; l++)
	{
		i=0;
		for( j = 0 ; j < 12; j++)
		{
			i++;
			for( ; pbuff[i] != ' '; i++);
		}

		for(c = 13; c <= 16; c++)
		{
			i++;	
			for( j = 0; pbuff[i] != ' '; i++)
			{
				temp[j] = pbuff[i];
				j++;
			}

			temp[j] = '\0';
			value = (int)atoi(temp); //converting ascii to integer
			//printf(" ---> value :%d\n", value);
			sum = sum + value;
			printf("sum=%d\n",sum);
		}
		printf("------------\n");
		sum = 0;
	}
}

main()
{
	get_giffs(data);
}
