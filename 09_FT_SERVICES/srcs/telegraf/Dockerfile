FROM alpine:3.12

RUN apk add wget
RUN wget https://dl.influxdata.com/telegraf/releases/telegraf-1.15.3_static_linux_amd64.tar.gz
RUN tar -xvf telegraf-1.15.3_static_linux_amd64.tar.gz
RUn chmod +x telegraf-1.15.3/*
RUN cp -r telegraf-1.15.3/* /

COPY ./telegraf.conf /etc/telegraf/telegraf.conf
COPY ./start.sh .

RUN chmod +x start.sh

ENTRYPOINT ["sh", "start.sh"]
