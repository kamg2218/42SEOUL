FROM debian:buster

RUN apt-get -y update
RUN apt-get -y upgrade
RUN apt-get -y install nginx

#RUN apt-get -y install openssl vim
#RUN openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Lee/CN=localhost" -keyout localhost.dev.key -out localhost.dev.crt
#RUN mv localhost.dev.crt etc/ssl/certs/
#RUN mv localhost.dev.key etc/ssl/private/
#RUN chmod 600 etc/ssl/certs/localhost.dev.crt etc/ssl/private/localhost.dev.key

COPY ./srcs/init_start.sh .
COPY ./srcs/init_container.sh .
COPY ./srcs/default .
COPY ./srcs/phpinfo.php .
COPY ./srcs/config.inc.php .
COPY ./srcs/wp-config.php .

CMD bash init_start.sh
