FROM gcc:4.9
MAINTAINER bhagavan

COPY my_container.c /usr/src/my_container/my_container.c

WORKDIR /usr/src/my_container

RUN gcc -o /usr/bin/my_container /usr/src/my_container/my_container.c

CMD /usr/bin/my_container

