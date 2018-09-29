int main()
{
    int height=0, weight=1, volume=2, density=3;
    
	if( (height<density && weight>volume) || (volume>0 && density>weight) )
    printf("Perfect\n");
    if((height<density && weight<density) || (volume>weight && density>weight))
    printf("Excellent\n");
    
	else
         printf("Exceptional\n");

    return 0;
}


