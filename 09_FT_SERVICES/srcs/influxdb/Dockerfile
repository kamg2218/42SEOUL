FROM alpine:3.12

RUN apk update && apk --update --no-cache add \
    influxdb \
    --repository http://dl-2.alpinelinux.org/alpine/edge/community/

COPY influxdb.conf /etc/influxdb.conf
COPY start.sh .

EXPOSE 8086

ENTRYPOINT ["sh", "start.sh"]
