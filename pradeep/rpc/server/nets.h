int init_nets_communication(int srvr_port);
int read_from_client(fop_data_req *pcreq);
int write_to_client(fop_data_rep *psreply);
int close_nets_communication();
