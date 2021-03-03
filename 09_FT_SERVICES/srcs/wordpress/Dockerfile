FROM alpine:3.12

RUN apk update && apk upgrade
RUN apk add nginx
RUN apk add wget
RUN apk add php7 php7-fpm php7-opcache php7-dom php7-xmlreader php7-simplexml php7-mysqli php7-zlib php7-curl php7-xml php7-pdo php7-phar php7-openssl php7-pdo_mysql php7-gd php7-iconv php7-mcrypt php7-ctype php7-apcu php7-intl php7-mbstring php7-json php7-session fcgi php7-cgi openssl openssh-client mysql-client
RUN mkdir -p /run/nginx

RUN wget https://wordpress.org/latest.tar.gz
RUN tar -xvf latest.tar.gz
RUN mv wordpress /etc/

COPY default.conf /etc/nginx/conf.d/default.conf
COPY wp-config.php /etc/wordpress/
COPY wordpress.sql .
COPY ./start.sh .

EXPOSE 5050

CMD /bin/sh start.sh && /usr/sbin/php-fpm7 && nginx -g 'daemon off;'
