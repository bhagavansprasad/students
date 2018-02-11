#include "stdio.h"

int weight_table[1024*1024] = {0};
int is_table_built = 0;
int table_len = -1;

int build_weight_table(char *s)
{
	int i = 0;
    int j = 0, weight = 0;
 
	for (i = 1, j = 0; s[i] != '\0'; i++)
	{
		if (!islower(s[i]))
			continue;

		weight = weight + ((s[i-1] - 'a') + 1) ;
		weight_table[j++] = weight;
		if (s[i-1] != s[i])
		{
            printf("i :%d, : wt :%d\n", i, weight_table[j-1]);
			weight = 0;
		}
	}
	weight_table[j++] = weight + (s[i-1] - 'a' + 1);
    table_len = j;
    
    return 0;
}

void dump_table()
{
	int i = 0;
    
	for (i = 0; i < table_len; i++)
    {
        printf("%d:%d\n", i, weight_table[i]);
    }
    return;
}

main()
{
	build_weight_table("abccddde");
	dump_table();
}
