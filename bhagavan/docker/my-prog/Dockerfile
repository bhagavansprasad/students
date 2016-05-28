FROM gcc:4.9
MAINTAINER jim

COPY my_container.c /usr/src/my_container/my_container.c

WORKDIR /usr/src/my_container

RUN gcc -o /usr/bin/my_container /usr/src/my_container/my_container.c

ENV PORT 5000

CMD /usr/bin/my_container $PORT

EXPOSE 5000
