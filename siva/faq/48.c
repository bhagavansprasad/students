#define mysizeof(a) ((&(a)+1)- &(a))
main()
{
float d;
printf("%d\n",mysizeof(d));
}
