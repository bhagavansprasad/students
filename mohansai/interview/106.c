#include<stdio.h>
int main()    
{        
        static int i;
        int temp;
        for(i;i<16;i++)
        {
                temp = (1<<i)&i;
                printf("%d\n",temp);
        }
                printf("%d\n",temp);
        return 0;
}
