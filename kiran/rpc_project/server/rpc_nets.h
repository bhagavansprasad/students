int init_nets_communication(int srvr_port);

int server_read_from_client(fop_data_req *creq);

int server_write_to_client(fop_data_rep *sreplay);

int close_nets_communication(void);

int process_client_request(fop_data_req *creq, fop_data_rep *sreplay);
