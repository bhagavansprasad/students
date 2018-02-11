#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

typedef struct participant_t
{
    int  pos;
    char name[256];
    int  dec_count;
    int  jan_count;
    int  diff;
    int  rank;
}sdata;

#define MAX_NAME_LEN 200
sdata *phd = NULL;
int scount = 0;

int store_data(int n, char *name, int dc, int jc)
{
    if (phd == NULL)
    {
        phd = (sdata *)(malloc(sizeof(sdata) * n));
    }
    phd[scount].pos = scount;
    strncpy(phd[scount].name, name, MAX_NAME_LEN);
    phd[scount].dec_count = dc;
    phd[scount].jan_count = jc;
    phd[scount].diff = jc-dc;
    scount++;
    
    return 0;
}

int sort_based_on_diff(const void * elem1, const void * elem2) 
{
    sdata *a = (sdata *)elem1;
    sdata *b = (sdata *)elem2;
    
    if (a->diff < b->diff) return 1;
    if (a->diff > b->diff) return -1;
    return 0;
}

int sort_based_on_pos(const void * elem1, const void * elem2) 
{
    sdata *a = (sdata *)elem1;
    sdata *b = (sdata *)elem2;
    
    if (a->pos > b->pos) return 1;
    if (a->pos < b->pos) return -1;
    return 0;
}


void dump_data(void)
{
    int i = 0;
    printf("\n");
    for (i = 0; i < scount; i++)
    {
        printf("%d. %10s  %5d %5d %5d %5d\n", phd[i].pos, phd[i].name, phd[i].dec_count, phd[i].jan_count, 
               phd[i].diff, phd[i].rank);
    }
    return ;
}

int get_ranker(int n)
{
    int sp = 0, i = 0, c = 0;
    qsort(phd, scount, sizeof(sdata), sort_based_on_diff);
    //dump_data();
    
    sp = 0;
    for (i = 0; i < scount; i++)
    {
        if (phd[sp].diff == phd[i].diff)
        {
            c = c + 1;
        }
        else
        {
           if (c > 0)
           {
                qsort(&phd[sp], c, sizeof(sdata), sort_based_on_pos);
           }
           c = 0;
           sp = i;
        }
    }
    //dump_data();
    
    printf("%s %d\n", phd[0].name, phd[0].diff);
    return 0;
}

int main() {
    int n; 
    scanf("%i", &n);
    for(int a0 = 0; a0 < n; a0++){
        char* name = (char *)malloc(512000 * sizeof(char));
        int d; 
        int j; 
        scanf("%s %i %i", name, &d, &j);
        store_data(n, name, d, j);
    }
    get_ranker(n);
    // Write Your Code Here
    return 0;
}
