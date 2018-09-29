#include <stdio.h>
#include<string.h>

int word_cunt(char *p);

char str1[50]= "How Are You";
char str2[50]= "How Are";
char str3[50]= "How a";
char str4[50]= "H a a";
char str5[50]= "a";
char str6[50]= "How a are y you";
char str7[50]= "How are you a you";
char str8[50]= "How";

main()
{
	int t=0;

	t = word_cunt(str1);
	printf("-->string :%s, wcount :%d\n", str1, t);

	t = word_cunt(str2);
	printf("-->string :%s, wcount :%d\n", str2, t);

	t = word_cunt(str3);
	printf("-->string :%s, wcount :%d\n", str3, t);

	t = word_cunt(str4);
	printf("-->string :%s, wcount :%d\n", str4, t);

	t = word_cunt(str5);
	printf("-->string :%s, wcount :%d\n", str5, t);

	t = word_cunt(str6);
	printf("-->string :%s, wcount :%d\n", str6, t);

	t = word_cunt(str7);
	printf("-->string :%s, wcount :%d\n", str7, t);

	t = word_cunt(str8);
	printf("-->string :%s, wcount :%d\n", str8, t);
}


int word_cunt(char *p)
{
	int i=0,n,sum=0,count=0;

	for(i = 0; p[i] != '\0'; i++)
	{
		if (p[i] == ' ')
			count++;
	}
	count=count+1;
	printf("-->Before returning count :%d\n", count);
	return (count);
}
