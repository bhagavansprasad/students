int ovc()
{
	for (;;)
	{
		read_giffs_from_pipe(rfd, &pid, &giffs);
		cpu_occ = store_into_db(pid, giffs);

		print(cpu_occ);

		take_action(pid, cpu_occ);
		clean_up_db();
	}
}
