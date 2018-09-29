//Program to find the month
// Using the data structur
#include<stdio.h>
int main()
{
    enum months {Jan=1,Feb,Mar,Apr,May,Jun,Jul,Aug,Sep,Oct,Nov,Dec};
    enum months a;

    printf("month=%d\n",a=Feb);
    printf("month=%d\n",a=Apr);
    printf("month=%d\n",a=Nov);
    return 0;
}
