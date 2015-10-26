int get_signature()
{
	read first 3 bytes
}

	get_version()
	{
		read first 1 bytes
	}

read_header(int fd)
{
	get_signature();
	get_version()
	get_flags()
	get_data_offset()
}

read_meta_data();
{
	read_previous_tag_size();
}

read_audio_data()
{
}

read_tag()
{
	read_tag_type()

		switch(type)
		{
		case TAG_META_DATA:
			read_meta_data();
			break;

		case TAG_AUDIO_DATA:
			read_audio_data();
			break;

		case TAG_VIDEO_DATA:
			read_vedio_data();
			break;
	}
}

main()
{
	fd = open_flv_file()

	...

	read_header(fd);

	for(;;)
	{
		read_tag()
	}
}

             /*          */

open_file()
{
	int fd;
	fd=open("sixth.flv",O_RDONLY);
	if(fd==-1)
	{
		perror("File is not opened\n");
		exit(0);
	}
}
read_header()
{
	get_signature();
	get_version();
	get_flags();
	get_data_offset();
}

 void get_signature()
 {
  int val=0;
  val=read


read_meta_data();
{
	read_previous_tag_size();
}

read_tag()
{
	read_tag_type()

		switch(type)
		{
			case TAG_META_DATA:
				read_meta_data();
				break;

			case TAG_AUDIO_DATA:
				read_audio_data();
				break;
			case TAG_VIDEO_DATA:
				read_vedio_data();
				break;
		}
}



main()
{
   flv_header header;

	open_file();

	...

		read_header();

	for(;;)
	{
		read_tag()
	}
}

