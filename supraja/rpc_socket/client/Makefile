CFLAGS := -g
#CFLAGS += -Wall
#CFLAGS += -Werror

c : client.o fop.o rpcc.o rpcc_send_req.o tcp_clint.o debug_before_write.o 
	gcc $(CFLAGS)  client.o fop.o rpcc.o rpcc_send_req.o tcp_clint.o debug_before_write.o  -o c 

client.o : client.c fop.h struct_replay.h
	gcc  $(CFLAGS) -c client.c

fop.o : fop.c rpcc.h
	gcc  $(CFLAGS) -c fop.c

rpcc.o : rpcc.c struct_req.h struct_replay.h rpcc_send_req.h
	gcc  $(CFLAGS) -c rpcc.c

rpcc_send_req.o : rpcc_send_req.c
	gcc  $(CFLAGS) -c rpcc_send_req.c

tcp_clint.o:tcp_clint.c
	gcc  $(CFLAGS)  -c tcp_clint.c

debug_before_write.o: debug_before_write.c struct_req.h
	gcc  $(CFLAGS)  -c  debug_before_write.c

clean : 
	
	rm -rf *.o
	rm -rf c

