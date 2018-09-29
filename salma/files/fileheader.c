int aopen(char *a,int m,int f)
{
int fd=open(a,m,f);
return fd;
}
int aread(int fd1,char *buff,int l)
{
int r=read(fd1,buff,l);
return r;
}
int awrite(int fd2,char *buff,int r)
{
 return write(fd2,buff,r);
}
int aclose(int fd1)
{
 return close(fd1);
}
