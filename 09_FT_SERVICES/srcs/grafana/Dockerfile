FROM alpine:3.12

RUN apk add grafana=7.3.6-r0 --repository=https://dl-cdn.alpinelinux.org/alpine/latest-stable/community/

COPY ./srcs/grafana.ini /etc/grafana/grafana.ini
COPY ./srcs/dashboards /var/lib/grafana/dashboards
COPY ./srcs/provisioning/dashboards/dashboards.yaml /usr/share/grafana/conf/provisioning/dashboards/dashboards.yaml
COPY ./srcs/provisioning/datasources/influxdb.yaml /usr/share/grafana/conf/provisioning/datasources/influxdb.yaml

EXPOSE 3000

CMD /usr/sbin/grafana-server --homepath=/usr/share/grafana --config=/etc/grafana.ini

