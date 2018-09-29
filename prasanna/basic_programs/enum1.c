#include<stdio.h>
int main()
{
    enum months {Jan,Feb,Mar,Apr=-3,May,Jun,Jul,Aug,Sep,Oct,Nov,Dec};
    enum months month;
    printf("month=%d\n",month=Jan);//Assign integer value
    printf("month=%d\n",month=Feb);//Assign integer value
    printf("month=%d\n",month=Mar);//Assign integer value
    printf("month=%d\n",month=Apr);//Assign integer value
    printf("month=%d\n",month=May);//Assign integer value
    printf("month=%d\n",month=Jun);//Assign integer value
    printf("month=%d\n",month=Jul);//Assign integer value
    printf("month=%d\n",month=Aug);//Assign integer value
    printf("month=%d\n",month=Sep);//Assign integer value
    printf("month=%d\n",month=Oct);//Assign integer value
    printf("month=%d\n",month=Nov);//Assign integer value
    printf("month=%d\n",month=Dec);//Assign integer value



    return 0;
}
