int aopen(char *fname, int flags);
int aread(int fd, char *buf, int count);
 int awrite(int fd, char *buf, int count);
 int alseek(int fd, int offset, int whence);
int aclose(int fd);
int init_communication_channel_server(int port);
int rpc_send_reply(fop_data *reply);
int rpc_recv_data(fop_data *datac);
