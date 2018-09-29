/*
main()
{
 sleep(50);
 printf("rajini kanth reddy\n");
}
main()
{
 for( ; ; );
}

main()
{ 
 printf("run the pe -el command \n");
 sleep(50);
 printf("run the pe -el command once more \n");
 for( ; ; );
}
*/


main()
{
 int pid=0,i=0,j=0;
 pid = fork();

 if(pid==0)
  {
    for(i=0;i<500;i++)
	printf("%d\t",i);
   }
   else
   {
    for(j=0;j<500;j++)
	printf("%d..",j);
   }
 } 
