#include<stdio.h>
int main( )
{
    struct node
    {
        int data ;
        struct node *link ;
    } ;
    struct node r;
    struct node *p,*q;
    p=&r;
    p = malloc ( sizeof ( struct node ) ) ;
    q = malloc ( sizeof ( struct node ) ) ;
    p -> data = 30 ;
    p -> link = q ;
    q -> data = 40 ;
    q -> link = NULL ;
    printf ( "%d", p -> data ) ;
    p = p -> link ;
    printf ( "%d", p -> data ) ;
    return 0;
}

	
