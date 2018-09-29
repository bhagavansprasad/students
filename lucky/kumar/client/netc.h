
int init_netc_communication(char *srvr_ip, int srvr_port);
int write_to_server(fop_data_req *pcreq);
int read_from_server(fop_data_rep *psreply);
int close_netc_communication(void);
