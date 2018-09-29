#include <stdio.h>
#include <string.h>

struct mystrings_t
{
	char s1[100];
	char s2[100];
	char hr_string[100];
};

struct mystrings_t strings[] = {
									{"ISO015000050", "ISO015000050"},
									{"03456","456"},
									{"0044564","4564"},
									{"0428132710","0428132710"}
								};
int conv(char digit)
{
	if(digit)
		return digit-'0';
	else if(digit>='a'&&digit<='f')
		return 10+digit-'a';
	else if(digit>='A'&&digit<='F')
		return 10+digit-'A';
}
char * id_code(char  *d,char *s)
{
	int a =conv(*s);
	int b =conv(*(s+1));
	int c =conv(*(s+2));
	int len = a*100+b*10+c;
	strncpy(d,s+3,len);
	return d;
}
char *proc_code(char *d, char *s)
{
		strncpy(d,s,12);
		printf("%s\n",d);
		return d;
} 
char * date_time_transmission(char *d,char *s)
{
	
	strncpy(d,s,10);
	printf("%s\n",d);
	return d;
}

main()
{
	char output[10];
	int i;
	char *retval;
	printf("%d\n",sizeof(strings));
	printf("%d\n",sizeof(struct mystrings_t));
	printf("%d\n",sizeof(strings)/sizeof(struct mystrings_t));
//	for(i=0;i<sizeof(strings)/sizeof(struct mystrings_t))
//	{
//		printf("%s\n",strings[3].s1);
		retval = date_time_transmission(output,strings[3].s1);
		printf("%s\n",output);
		if (strcmp(output, strings[3].s2) != 0 )
		{

				printf("-->%d. NOT SAME strings \'%s\' and \'%s\'\n",4,output,strings[3].s2);
		}
//	} 	
}
