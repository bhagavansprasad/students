#include <stdio.h>

#include <algorithm.h>


//using namespace  std;


char str[]="WHYNUTOPAE";

char inv[128];


//Array that stores the current permutation

int ar[]={0,1,2,3,4,5,6,7,8,9};


//Convert string to integer based on current values of the permuation

int wordtonum(const char *s,int N)

{

  int ret=0;

  for(int i=0;i<N;i++)

  {

    ret=ret*10+ar[inv[s[i]]];

  }

  return ret;

}


int main()

{

  for(int i=0;i<10;i++)

    inv[str[i]]=i;


  do

  {

    int m1=wordtonum("WHY",3);

    int m2=wordtonum("NUT",3);

    

    int t1=wordtonum("OONP",4);

    if(t1!=m1*wordtonum("T",1))continue;

    int t2=wordtonum("OYPY",4);

    if(t2!=m1*wordtonum("U",1))continue;

    int t3=wordtonum("OUHA",4);

    if(t3!=m1*wordtonum("N",1))continue;

    

    int s=wordtonum("ONEPOP",6);

    if(s!=m1*m2)continue;


    printf("%s = ",str);

    for(int i=0;i<10;i++)

      printf("%d",ar[i]);

    printf("\n");

  }while(next_permutation(ar,ar+10));

  return 0;

}



