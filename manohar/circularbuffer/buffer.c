#include <stdio.h>
#define MAX 100

int front=-1;

int add_elements(char *arr, char *buf_f)
{
	//printf("starting array---->%s\n",arr);
	int i;
	for(i = 0; arr[i] != '\0'; i++)
	{
		if(front == MAX-1)
		{
			front = 0;
			buf_f[front] = arr[i];
		}
		else
		{
			front++;
			buf_f[front] = arr[i];
		}
		//printf("arr[%d]---->%c\t",i,arr[i]);
		//printf("buf[%d]---->%c\n",front,buf_f[front]);
	}
	//printf("total buffer--->%s\n",buf_f);

	return 0;
}

int dump_buff(char *buff, int size)
{
	int i = 0;

	for (i = 0; i < size; i++)
		printf("%c", buff[i]);

	printf("\n");
}

int main()
{
	int i;
	char *a[10]={"aaaaaaaaaaaaaaaaa","bbbbbbb","cccccccccccccccccccccccccccccccccc","dddddddddddddddddddddddddddddddddddddddddd","eee","fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"};
	char buff[MAX] = "";

	for(i=0; i <= 5; i++)
	{
		printf("Adding :%s\n", a[i]);
		add_elements(a[i], buff);
		dump_buff(buff, MAX);
	}
}
