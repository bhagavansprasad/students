#include "stdio.h"
#include "utils.h"

void xmppc_execute_state_machine(void);
int set_program_to_viewed_by_id(int id)
{
	return 0;
}

int xcatalog_populate_planner(char *preply, int *prlen, int count)
{
	return 0;
}

int delete_catalog_event_by_index(char *preply, int *prlen, int index)
{
	return 0;
}

int rename_prog_channel_number_by_index(char *preply, int *prlen, int index, int new_number)
{
	return 0;
}

int rename_prog_name_by_index(char *preply, int *prlen, int index, char *nname)
{
	return 0;
}

int xmpp_record_live(char *preply, int *prlen)
{
	return 0;
}

int main()
{
	XMPP_DEBUG("-->Starting xmpp client\n");
	xmppc_execute_state_machine();

	return 0;
}


