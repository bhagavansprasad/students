int ovd(int wfd)
{
	for (;;)
	{
		int proc_list[1000];

		proc_count = read_list_of_processes(proc_list);
		for (1 to proc_count)
		{
			giffs = get_giffs_by_pid(proc_list[i])
			send_gifss_to_ovc(wfd, proc_list[i], giffs);
		}
		sleep(1);
	}
}
