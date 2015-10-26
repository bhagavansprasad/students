enum vehicles 
{ 
    car = -1,
    bus,
    bike
};
int main()
{
    enum vehicles v;
    if( v == car )
       printf("CAR\n");
    else if( v == bus )
       printf("BUS\n");
    else
       printf("BIKE\n");
    return 0;
}

