FROM php:5.6-apache
MAINTAINER Federico Kereki fkereki@gmail.com

COPY search.php /var/www/html/

RUN     apt-get update && \
        apt-get -q -y install php5-mysql && \
        docker-php-ext-install mysqli
