struct free_buff
{
	int is_free;
	void *ptr;
	struct free_buff *next;
	
};

struct free_buff *fpool1 = NULL;
struct free_buff *fpool2 = NULL;
struct free_buff *fpool3 = NULL;

int mem_req[10][3] = {
	{100, 5},
	{200, 3},
	{500, 4}
}

int populate_free_pool(char *bp)
{
	for(number of rows)
	{
		add_buff_to_free_pool(size_of_the_buffer, pointer_to_buffer);
	}
}

main()
{
	int mem_req = 0;
	char *bp = NULL;

	mem_req = caliculate_mem_requirements();

	bp = malloc(mem_req);

	populate_free_pool(bp);

}
