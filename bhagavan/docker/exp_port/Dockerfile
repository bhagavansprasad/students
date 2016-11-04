FROM gcc:4.9
MAINTAINER jim

COPY tcpechoserver.c /usr/src/tcpechoserver/tcpechoserver.c

WORKDIR /usr/src/tcpechoserver

RUN gcc -o /usr/bin/tcpechoserver /usr/src/tcpechoserver/tcpechoserver.c

ENV PORT 5000

CMD /usr/bin/tcpechoserver $PORT

EXPOSE 5000
