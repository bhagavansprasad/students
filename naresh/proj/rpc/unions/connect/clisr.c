int main()void
{
	for(i = 0;i < 10;i++)
	{
		sleep(1);
		retval = write(socketfd,&buff1[i],20);
		printf("retval of write: %d\n",retval);
		if(retval == -1)
		{
			perror("write failed");
			exit(0);
		}

		read_retval = read(socketfd,sbuff,sizeof(sbuff));
		if(read_retval == -1)
		{
			perror("read failed");
			exit(0);
		}
		
		printf("-->client: buffer read from servor :%s\r\n",sbuff);
		
		t = strcmp(sbuff,"bye");
		if(t == 0)
		{
			exit(0);
		}
		
	}
	close(socketfd);
		return 0;
}

