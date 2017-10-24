FROM ubuntu

# install nginx
RUN apt-get update && apt-get install -y nginx
RUN rm -rf /etc/nginx/sites-enabled/default

# forward request and error logs to docker log collector
RUN ln -sf /dev/stdout /var/log/nginx/access.log
RUN ln -sf /dev/stderr /var/log/nginx/error.log

COPY index.html /usr/share/nginx/html
COPY test.html /usr/share/nginx/html
COPY nginx.conf /etc/nginx

EXPOSE 80 443
CMD ["nginx", "-g", "daemon off;"]
