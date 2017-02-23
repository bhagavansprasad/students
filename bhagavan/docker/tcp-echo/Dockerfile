FROM ubuntu
FROM gcc:4.9
MAINTAINER bhagavan

COPY tcpechoserver.c /usr/src/tcpechoserver/tcpechoserver.c

WORKDIR /usr/src/tcpechoserver

RUN gcc -o /usr/bin/myechoserver /usr/src/tcpechoserver/tcpechoserver.c

ENV PORT 8888

CMD /usr/bin/myechoserver $PORT

EXPOSE $PORT
