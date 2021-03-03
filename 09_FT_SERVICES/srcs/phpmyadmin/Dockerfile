FROM alpine:3.12

RUN apk update && apk upgrade
RUN apk add nginx
RUN mkdir -p /run/nginx

RUN apk add php7 php7-fpm php7-opcache php7-dom php7-xmlreader php7-simplexml php7-mysqli php7-zlib php7-curl php7-xml php7-pdo php7-phar php7-openssl php7-pdo_mysql php7-gd php7-iconv php7-mcrypt php7-ctype php7-apcu php7-intl php7-mbstring php7-json php7-session fcgi php7-cgi openssl openssh-client mysql-client
RUN apk add wget
RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz
RUN tar -xvf phpMyAdmin-5.0.2-all-languages.tar.gz
RUN mv phpMyAdmin-5.0.2-all-languages phpmyadmin
RUN mv phpmyadmin /etc/

COPY ./default.conf /etc/nginx/conf.d/default.conf
COPY ./config.inc.php /etc/phpmyadmin/config.inc.php
COPY ./phpinfo.php /etc/phpmyadmin/phpinfo.php

EXPOSE 5000

CMD php-fpm7 && nginx -g 'daemon off;'
