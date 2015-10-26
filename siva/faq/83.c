#if 0
typedef struct st
{
int i;
char b;
}

	node;
main()
{
struct st node1;
node1.i=55;
printf("%d\n",node1.i);
}
#endif

#if 0
int display()
{
printf("Hello World\n");
}

struct item
{
int i;
int display();
//{
//printf("Hello World\n");
//}
};
main()
{
struct item vara;
vara.dispaly();
}

#endif

struct item
{
int (*ptr)();
};
int display()
{
printf("Dennis Ritchie \n");
}
main()
{
struct item object;
object.ptr = display;
object.ptr();
}
