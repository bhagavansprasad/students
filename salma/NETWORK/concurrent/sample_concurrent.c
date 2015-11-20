pid_t pid;
int listenfd, connfd;
listenfd = socket(...);

/***fill the socket address with server’s well known port***/

bind(listenfd, ...);
listen(listenfd, ...);

for ( ; ; ) {

   connfd = accept(listenfd, ...); /* blocking call */

   if ( (pid = fork()) == 0 ) {

      close(listenfd); /* child closes listening socket */

      /***process the request doing something using connfd ***/
      /* ................. */

      close(connfd);
      exit(0);  /* child terminatescloswe
    }
    close(connfd);  /*parent closes connected socket*/
}
}
