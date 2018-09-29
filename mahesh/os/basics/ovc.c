struct student
{
	int pid;
	int giffies;
}rc;
void ovc(int p)
{
int i, j, x, d, y = 0, r;
for (j=0; ; j++)
		{
			for(i = 0;i<5  ; i++)
			{
				r=read(p,&rc,12);
				printf("%d\n",rc.giffies);
				x=rc.giffies;
				d=x-y;
				y=x;
				if(i>=1)
				printf("pid :%d\t difference is :%d\n", rc.pid, d);
				//sleep(1);
			}
				sleep(1);
	}
}
