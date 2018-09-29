#include <stdio.h>
#include <string.h>

struct student 
{
    int id;
    char name[30];
    float percentage;
};

int main() 
{
    int i;
    struct student record1 = {1,"Raju",90.5};
    struct student record2,*record3,record4,*ptr1;
    //1st method --> accessing structur variable// 
    printf("-->1 Records of STUDENT1 - record1 structure \n");
    printf("Id : %d \nName : %s\nPercentage : %f\n",record1.id,record1.name,record1.percentage);


    //2nd method --> copy whole structure to another structure//
    record2=record1;    
    printf("\n-->2 Records of STUDENT1 -->Direct copy from record1 \n");
    printf("Id : %d \nName : %s\nPercentage : %f\n",record2.id,record2.name,record2.percentage);


    //3rd method --> copy by individual members//
    printf("\n-->3 Records of STUDENT1 -->Cope from individual members from record1 \n");
    record4.id=record1.id;
    strcpy(record4.name, record1.name);
    record4.percentage = record1.percentage;
    printf("  Id : %d \n  Name : %s\n  Percentage : %f\n",record4.id,record4.name,record4.percentage);


    //4th method --> copy using memcpy function //
    ptr1 = &record1; 
    memcpy(record3,ptr1,sizeof(record1));
    printf("\n-->4 Records of STUDENT1 -->copied from record1 using memcpy \n");
    printf("Id : %d \nName : %s\nPercentage : %f\n",record3->id,record3->name,record3->percentage);
    return 0;
}
