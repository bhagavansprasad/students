
#include<stdio.h>
struct st
{
    char s1[100];
    char s2[100];
    int res;
};

struct st t[20]={
    {"aura","auma", 1},
    { "ravi","ravi", 0},
    { "paidi","paidi", 0},
    { "shiva","shiva", 0},
    { "hai","hai", 0},
    { "sudha","sai", 1},
    { "hari","nag", 1},
    { "dill","name", 1},
    { "nAme","name", 0},
};

int astrcmp(s1, s2)
    char *s1, *s2;
{
    int i = 0;
    for(i = 0; (s1[i]) && (s1[i] == s2[i]); i++);

    return s1[i] - s2[i];
}

main()
{
    int i, retval;

    for(i = 0; i < 9; i++)
    {
        retval = astrcmp(t[i].s1,t[i].s2);

        if (retval != t[i].res)
        {
            printf("expected result is :%d, BUT RETURNED :%d\n", t[i].res, retval);
            printf("strings are : %-30s <--> %30se\n", t[i].s1, t[i].s2);
        }
    }
#if 0
        if (retval == t[i].res)
            printf("%-30s <--> %30s are same :%d\n", t[i].s1, t[i].s2, retval);
        else
            printf("%-30s <--> %30s are NOT SAME :%d\n", t[i].s1, t[i].s2, retval);
#endif

    }

