#include <stdio.h>

#define toggle(num,pos) ((num = num^(1<<pos-1))? 1:0)
#define show_bits(num,pos) (num&(1<<(pos-1))?1:0)


void toggle_m_n_bits(int num, int m, int n)
{
	int i, count=1;
//	for(i = 1;i<= 8; i++)
	for(i = 16; i > 0; i--)
	{
	
	//	if( i >=m && count <= n)
		if(i <= (m+n-1) && count <=n)
		{
			toggle(num ,i);
			count++;
		}
		printf("%d", show_bits(num,i));
	}
	printf("\n");
//	printf("%d\n",num);
}
toggle_ver2(int num, int from, int to)
{
	int mask = 0;
	mask = ((1 << to)-1) ^ ((1<< from-1)-1);
	printf(" mask= %x\n",mask);
	return num^mask;
}

main()
{
int i;
//		toggle_m_n_bits(215,3,4);
			for(i = 16; i > 0; i--)
				printf("%d", show_bits(321,i));
				printf("\n");
			
	//	toggle_m_n_bits(321,3,4);
#if 1	
	int val = toggle_ver2(215,3,7);
		for(i = 16; i > 0; i--)
				printf("%d", show_bits(val,i));
				printf("\n");
#endif
}
