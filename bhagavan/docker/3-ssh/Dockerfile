FROM ubuntu
MAINTAINER bhagavan
#ADD tcpecho /usr/bin
#ENV PORT 5555 
#CMD /usr/bin/tcpecho $PORT
#EXPOSE $PORT

RUN apt-get update 
RUN apt-get install -y openssh-server telnetd
RUN apt-get install -y net-tools
RUN apt-get install -y python
RUN mkdir /var/run/sshd
RUN echo 'root:jnjnuh' | chpasswd
RUN sed -i 's/PermitRootLogin prohibit-password/PermitRootLogin yes/' /etc/ssh/sshd_config

# SSH login fix. Otherwise user is kicked off after login
RUN sed 's@session\s*required\s*pam_loginuid.so@session optional pam_loginuid.so@g' -i /etc/pam.d/sshd

ENV NOTVISIBLE "in users profile"
RUN echo "export VISIBLE=now" >> /etc/profile

EXPOSE 22

CMD  ["mkdir", "-p", "/root/.ssh"]
COPY id_rsa.pub "/root/.ssh/authorized_keys"
CMD  ["ssh-keygen", "-f", "id_rsa", "-t", "rsa", "-N", "''"]
CMD ["/usr/sbin/sshd", "-D"]
