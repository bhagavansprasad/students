#include<stdio.h>
int arr[]={10,20,30,40,50};
int i, *ptr;
/* valuse are order print*/

/*main()
{
for(ptr=arr,i=0;i<=4;i++)
{
printf("val--> %d\n",ptr[i]);
printf("add--> %u\n",&ptr[i]);

}
}*/

/*1) reverse print */

/*main()
{
for(ptr=arr+4;ptr>=arr;ptr--)
{
printf("val--> %d\n",*(ptr));
printf("address--> %u\n",&ptr[4]);
}*/
/*2) reverse next model*/
/*main()
{
for(ptr=arr+4,i=0;i<=4;i++)
{
printf("valu--> %d\n",ptr[-i]);
printf("address--> %u\n",&ptr[-i]);
}
}
*/
/* (1/1) valu missing*/
/*
main()
{
	for(ptr=arr,i=0;ptr+i<=arr+4;ptr++,i++)
	{
		printf("valu--> %d\n",ptr[i]);
		printf("address--> %u\n",&ptr[i]);
	}
}
*/

/* (1/1) valu missing */
main()
{
for(ptr=arr+4,i=0;ptr+i>=arr+0;ptr--,i--)
{
printf("valu--> %d\n",ptr[i]);
printf("address-->= %u\n",&ptr[i]);

}
}

