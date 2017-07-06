int ins_ele(int *a,int n,int pos,int k)
{										
	int i=0,j;                              											
	for(i=0; i<k; i++)					  	
	{
		if(i==pos)
		{
			for (j=k; j>=pos; j--)
				a[j+1]=a[j];
			a[pos]=n;
		}
	}
	return a[i];
}
