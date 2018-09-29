#include <stdio.h>
main()
{
	char a[]="aaabbcaaaabbbbbss";
	char b[25];
	char ch[6];
	int e[6];
	int i,j,k=0,len=0,count;
	len = strlen(a);
	for(i=0;i < len;i++)
	{
		if(a[i]!=0)
		{
			ch[k]=a[i];
			count=0;
			for(j=i;;j++)
			{
				if(a[j]==ch[k])
				{
					count ++;
					a[j]=0;
				}
				else
					break;
			}
			e[k]=count;
			k++;
		}
	}
sprintf(b,"%c%d%c%d%c%d%c%d%c%d%c%d",ch[0],e[0],ch[1],e[1],ch[2],e[2],ch[3],e[3],ch[4],e[4],ch[5],e[5]);
printf("---------->:%s\n",b);
}

