FROM alpine:3.12

RUN apk update && apk upgrade
RUN apk add mysql
RUN mkdir -p /run/mysqld

COPY my.cnf /etc/my.cnf
COPY init .
COPY start.sh .

EXPOSE 3306

ENTRYPOINT ["sh", "./start.sh"]
