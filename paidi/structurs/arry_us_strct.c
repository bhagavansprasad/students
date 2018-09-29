#include <stdio.h>
#include <string.h>

struct student 
{
     int id;
     char name[30];
     float percentage;
};

struct student record[2];

int main() 
{
     int i;
     // 1st student's record
     record[0].id=1;
     strcpy(record[0].name, "paidi");
     record[0].percentage = 86.5;

     // 2nd student's record         
     record[1].id=2;
     strcpy(record[1].name, "kumar");
     record[1].percentage = 90.5;

     // 3rd student's record
     record[2].id=3;
     strcpy(record[2].name, "vadranapu");
     record[2].percentage = 81.5;

     for(i=0; i<3; i++)
     {
         printf("Records of STUDENT : %d \n", i+1);
         printf(" Id is: %d \n", record[i].id);
         printf(" Name is: %s \n", record[i].name);
         printf(" Percentage is: %f\n\n",record[i].percentage);
     }
     return 0;
}

