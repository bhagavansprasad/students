main()
{
int pid;
pid=fork();
if(pid>0)
printf("parent process%d\n",pid);
//µelse
//printf("child process %d\n",pid);
}
