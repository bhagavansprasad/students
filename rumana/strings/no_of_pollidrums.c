#include<stdio.h>
#include<string.h>
main()
{
char str[]="hello madam liril";
int count;
count = get_no_of_pollindrums(str);
printf("no of pollindrums is %d\n",count);

}

int get_no_of_pollindrums(char *str)
{
	char *f,*r,*c;
	int count=0;

	f=str;
	//printf("str is %u\n",str);
 	//printf("f is %u\n",f);

	while(*str != '\0')
	{
		if(*str==' '||*(str+1)=='\0')
		{
        	r=str-1;
			//printf("r is % d \n",r);
          	c=str+1;

			//printf("c is %u\n",c);
		
			if(*(str+1)=='\0')
			{
				r=str;
				c=str;
			}	

			//printf("str : %u in first while loop \n",str);
			while(r!=f)
			{
            	while(*f==*r)
				{
					if(f>=r)
					{
						count++;
						printf("count is %d\n",count);
						break;
					}
					f++;
					r--;
                	
				}
	        	f=c;
				break;

			}
		}
        str++;
		//printf("end of main loop %u \n",str);

	}

	return(count);

}
