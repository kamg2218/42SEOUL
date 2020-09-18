FROM debian:buster

RUN apt-get -y update
RUN apt-get -y upgrade
RUN apt-get -y install nginx

COPY ./srcs/init_start.sh .
COPY ./srcs/init_container.sh .
COPY ./srcs/default .
COPY ./srcs/phpinfo.php .
COPY ./srcs/config.inc.php .
COPY ./srcs/wp-config.php .

CMD bash init_start.sh
