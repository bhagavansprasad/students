#include <stdio.h>
#include <string.h>
#include <fcntl.h>
main()
{
	char url[1000];
	char buff[100];
	char ch[100]="src";
	char ch1[100]="you are left with only";
	int fd=0;
	system("wget http://www.airtel.in/smartbyte-s/page.html");
	fd=open("page.html",0,0_RDONLY);
	do
	{
	read(fd,url,100);
	if(url==ch)
	{
	read(fd,url,10000);
		print(url)

	index = substring(buff, "src=");

	read_url(buffer + index, url);

	print(url);
}
