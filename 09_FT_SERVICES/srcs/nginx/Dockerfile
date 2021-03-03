FROM alpine:3.12

RUN apk update
RUN apk upgrade
RUN apk add --no-cache nginx openssl openssh

#openssl
RUN openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Lee/CN=localhost" -keyout localhost.dev.key -out localhost.dev.crt
RUN mv localhost.dev.crt etc/ssl/certs/
RUN mv localhost.dev.key etc/ssl/private/
RUN chmod 600 etc/ssl/certs/localhost.dev.crt etc/ssl/private/localhost.dev.key
RUN mkdir -p /run/nginx

#openssh
RUN sed 's/#PermitRootLogin prohibit-password/PermitRootLogin yes/' -i /etc/ssh/sshd_config
RUN echo "Port 22" >> /etc/ssh/sshd_config
RUN echo 'root:pass' | chpasswd
RUN ssh-keygen -f /etc/ssh/ssh_host_rsa_key -N '' -t rsa
RUN ssh-keygen -f /etc/ssh/ssh_host_dsa_key -N '' -t dsa
RUN mkdir -p /var/run/sshd
RUN mkdir -p /var/www/html

COPY ./default.conf ./etc/nginx/conf.d/default.conf
COPY ./index.html ./var/www/html/index.html
COPY ./start.sh ./start.sh

RUN chmod +x start.sh

EXPOSE 22
EXPOSE 80
EXPOSE 443

ENTRYPOINT ["sh", "./start.sh"]
