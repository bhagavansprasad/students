#include<stdio.h>
#include<unistd.h>
main()
{
	int pid,p[1];
	char str[30]="add 10 20";
	char buff[100];
	char opera[30];
	int first,second,w,r;
	int add,sub,mul,div,mod;
	pipe(p);
	pid=fork();
	if(pid>0)
	{  
	    sleep(2);
	   r=read(p[0],buff,sizeof(str));
	   printf("read is %s\n",buff);
	   sscanf(buff,"%s%d%d",opera,&first,&second);
	   printf("operation is %s\n",opera);
	   printf("first is %d\n",first);
	   printf("second is %d\n",second);

		if(strcmp(opera,"add")==0)
		{
			add=first+second;
			printf("addtion is %d\n",add);
        }
		else if(strcmp(opera,"sub")==0)
		{
			sub=first-second;
			printf("substract is %d\n",sub);
		}

		else if(strcmp(opera,"mul")==0)
		{
			mul=first*second;
			printf("muliplication is %d\n",mul);
		}
		else if(strcmp(opera,"div")==0)
		{
			div=first/second;
			printf("division is %d\n",div);
		}

		else if(strcmp(opera,"mod")==0)
		{
			mod=first%second;
			printf("mod div is %d\n",mod);
		}
		else
			printf("wrong option");
	}

	else
	{
    	w=write(p[1],str,sizeof(str));
		printf("write is %s\n",str);

	}



}
