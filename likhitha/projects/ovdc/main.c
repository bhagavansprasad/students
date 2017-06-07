#include <stdio.h>

char data[1024] ="1734 (a.out) R 1555 1734 1555 34817 1734 4210688 75 0 0 0 951 3464 0 0 20 0 1 0 127576 2080768 136 4294967295 134512640 134514140 3213698384 3213696648 3078016332 0 0 0 0 0 0 0 17 1 0 0 0 0 0 134520584 134520868 163672064 3213701539 3213701545 3213701545 3213705204 0";
int get_giffs(char *pbuff)
{
	int words = 0, x, i = 0, j = 0, value = 0, sum = 0;
	char temp[100] = "";
	for( x = 0; x < 3; x++)
	{
		i = 0;
		words = 0;
		//printf("%s\n", pbuff); 
		for( ; words != 13 && pbuff[i] != '\0'; i++) //getting 14th word
		{
			if (pbuff[i] == ' ')
				words++;
		}
		printf("i     :%d\n", i); 
		printf("words :%d\n", words); 
		//printf("%s\n", &pbuff[i]); 

		sum = 0;
		for(words = 0 ; words < 4; words++)
		{
			for( ; pbuff[i] != ' '; i++, j++)
				temp[j] = pbuff[i];
			temp[j] = '\0';
			i++;
			value =(int) atoi(temp); //converting ascii to integer
			printf("value :%d\n", value);
			sum = sum + value;
			//	i++;	
			j = 0;

		}
		printf("sum=%d\n\n",sum);
		temp[100];
	}
}

main()
{
	get_giffs(data);
}
