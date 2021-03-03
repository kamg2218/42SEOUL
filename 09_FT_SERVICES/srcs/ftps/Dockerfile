FROM alpine:3.12

RUN apk update && apk upgrade
RUN apk add vsftpd openssl --no-cache
RUN openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Lee/CN=localhost" -keyout localhost.dev.key -out localhost.dev.crt
RUN mv localhost.dev.crt etc/ssl/certs/
RUN mv localhost.dev.key etc/ssl/private/
RUN chmod 600 etc/ssl/certs/localhost.dev.crt etc/ssl/private/localhost.dev.key

COPY ./vsftpd.conf /etc/vsftpd/vsftpd.conf

RUN mkdir -p /ftps/user \
		&& adduser --home=/ftps/user -D user\
		&& chmod -R 777 /ftps/user \
		&& echo "user:pass" | chpasswd
COPY ./start.sh ./start.sh

EXPOSE 20
EXPOSE 21
EXPOSE 21009-21010

ENTRYPOINT ["sh", "start.sh"]
