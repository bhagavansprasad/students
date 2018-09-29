#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <ctype.h>

long weight_table[1024*1024] = {0};
long is_table_built = 0;
long table_len = -1;

int b_cmpfunc(const void * a, const void * b) 
{
   return ( *(long int*)a - *(long int*)b );
}

int comp (const void * elem1, const void * elem2) 
{
    long int f = *((long int*)elem1);
    long int s = *((long int*)elem2);
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}

long int build_weight_table(char *s)
{
	long int i = 0;
    long int j = 0, weight = 0;
 
	for (i = 1, j = 0; s[i] != '\0'; i++)
	{
		weight = weight + ((s[i-1] - 'a') + 1) ;
		weight_table[j++] = weight;
		if (s[i-1] != s[i])
		{
            //printf("i :%d, : wt :%d\n", i, weight_table[j-1]);
			weight = 0;
		}
	}
	weight_table[j++] = weight + (s[i-1] - 'a' + 1);
    table_len = j;
    
    return table_len;
}

void dump_table()
{
	long int i = 0;
    
	for (i = 0; i < table_len; i++)
    {
        //printf("%d:%d\n", i, weight_table[i]);
    }
    return;
}

int is_weight_available(char *s, int x)
{
	long int i = 0;
    long int len = 0;
    long *item;

	if (is_table_built == 0)
	{
        len = build_weight_table(s);
        is_table_built = 1;
        
        qsort(weight_table, len, sizeof(long), comp);

        //dump_table();
    }
    
    item = (long int*) bsearch (&x, weight_table, table_len, sizeof (long int), b_cmpfunc);
    if (item != NULL)
        return 1;
    else
        return 0;
        
        
	for (i = 0; i < table_len; i++)
    {
        if (weight_table[i] == x)
            return 1;
    }
    return 0;
}

int main(){
    char* s = (char *)malloc(512000 * sizeof(char));
    scanf("%s",s);
    int n; 
    scanf("%d",&n);
    for(int a0 = 0; a0 < n; a0++){
        int x; 
        scanf("%d",&x);
        // your code goes here
        if (is_weight_available(s, x))
            printf("Yes\n");
        else
            printf("No\n");
        
    }
    return 0;
}

