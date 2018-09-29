void my_fun(void)
{
int idata1=10,idata2,idata3=3,idata4,iarray2[10]={1,2},sharray3[10]={5,6},i,j;
char carray1[10	],cname1[128]="aura networks",ch1=1,ch2,ch3=3;
char *pname1="aura networks";
short sh1,sh2=2,sh3,sh4=4;
	printf("%d\n",idata1);
	printf("%c\n",carray1);
	printf("%s\n",cname1);
//	printf("%s\n",*pname1);
	printf("%d\n",idata2);
	printf("%d\n", idata3 );
	printf("%d\n", idata4);
	printf("%d\n", sh1);
	printf("%d\n",sh2);
	for(i=0;i<2;i++)
	{
	printf("%d\n",iarray2[i] );
	}
	printf("%d\n", sh3);
	printf("%d\n", sh4 );
	printf("%d\n", ch1);
	printf("%c\n",ch2);
	for(j=0;j<2;j++)
	{
	printf("%d\n",sharray3[j]);
	}
	printf("%d\n",ch3);
}

