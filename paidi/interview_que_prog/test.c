main()
{
	int arr[]={1,2,2,3,3,4,5,6,8,9,9,8,7,7};
	int i,j;
	int arr2[10];
	

	for(i=0;arr[i]<=9;i++)
	{
	   arr2[j]=arr[i];
	   printf("valu%d\n",arr2[j]);
		for(j=i++;arr2[j]<=9;j++)
		{
			if(arr2[j]!=arr[i])
			{
			//	printf("%d\n",arr2[j]);
			}
								  
		
		}
	}
}

