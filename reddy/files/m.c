int aopen(char *p,int mode,int flag)
{
int fd;
fd=open(p,mode,flag);
return fd;
}
int aread(int q,char *buff,int len)
{
int r;
r=read(q,buff,len);
return r;
}
int aclose(int fd)
{
int t;
t=close(fd);
return t;
}
