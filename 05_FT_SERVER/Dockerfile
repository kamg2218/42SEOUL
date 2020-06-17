FROM debian:buster

RUN apt-get -y update
RUN apt-get -y upgrade
RUN apt-get -y install nginx
RUN apt-get -y install openssl vim

#openssl
RUN openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Lee/CN=localhost" -keyout localhost.dev.key -out localhost.dev.crt
RUN mv localhost.dev.crt etc/ssl/certs/
RUN mv localhost.dev.key etc/ssl/private/
RUN chmod 600 etc/ssl/certs/localhost.dev.crt etc/ssl/private/localhost.dev.key

#php-fpm
RUN apt-get -y install php-fpm

#mysql
RUN apt-get -y install mariadb-server php-mysql 

#phpmyadmin
RUN apt-get install -y wget
RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz
RUN tar -xvf phpMyAdmin-5.0.2-all-languages.tar.gz
RUN mv phpMyAdmin-5.0.2-all-languages phpmyadmin
RUN mv phpmyadmin /var/www/html/
RUN cp -rp var/www/html/phpmyadmin/config.sample.inc.php var/www/html/phpmyadmin/config.inc.php

#wordpress
RUN wget https://wordpress.org/latest.tar.gz
RUN tar -xvf latest.tar.gz
RUN mv wordpress var/www/html/
RUN chown -R www-data:www-data /var/www/html/wordpress
RUN cp var/www/html/wordpress/wp-config-sample.php var/www/html/wordpress/wp-config.php

#autoindex on
RUN rm var/www/html/index.nginx-debian.html

COPY ./srcs/default ./etc/nginx/sites-available/default
COPY ./srcs/phpinfo.php ./var/www/html/
COPY ./srcs/config.inc.php ./var/www/html/phpmyadmin/config.inc.php
COPY ./srcs/wp-config.php ./var/www/html/wordpress/wp-config.php
COPY ./srcs/init_container.sh .

EXPOSE 80
EXPOSE 443

CMD bash init_container.sh
