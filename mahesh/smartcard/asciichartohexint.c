#include <stdio.h>
struct DATA
{
	char s[20] ;
	int len;
};
struct DATA data[3]={
	{"3.proccode",6},
	{"4.amount",12},
	{"5.date",5}
};

char * astring(int a)
{
	printf("%s\n",data[2].s);
	return(data[a].s);
}
int conv(char c)
{
	int num;
	if(isdigit(c)) 
		num = c -'0';
	else if(c>='a' && c<='f')
		num = 10 + c - 'a';
	else if(c>='A' && c<='F')
		num = 10 + c - 'A';
	return num;
}

main()
{
	char a[20]="B23A800128A18018";
	int i,j,n=0;
	/*for(i=0;i<16;i++)
	{
		n=conv(a[i]);
	//	for(j=3;j>=0;j--)
		{
			static int count = 0;
			int m=0;
			m=n & (1<<j);
			count++;
			if(m!=0)
			{
		*/		//printf("%d\n",count);
				char *str  = astring(2); 
				printf("%s\n",str);
		//	}
		//}
	//}
}

