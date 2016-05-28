PORT=5000

tcpechoserver: tcpechoserver.c
	gcc tcpechoserver.c -o tcpechoserver
clean:
	rm tcpechoserver
run: tcpechoserver
	./tcpechoserver ${PORT}
test:
	printf "hello" | nc localhost ${PORT}
