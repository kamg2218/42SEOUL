minikube start --driver=virtualbox

eval $(minikube docker-env)

minikube addons enable metallb
minikube addons enable metrics-server
minikube addons enable dashboard

MINIKUBE_IP=$(minikube ip)
sed "s/MINIKUBE_IP/$MINIKUBE_IP/g" ./srcs/metallb/metallb_format.yaml > ./srcs/metallb/metallb.yaml
sed "s/MINIKUBE_IP/$MINIKUBE_IP/g" ./srcs/nginx/default_format.conf > ./srcs/nginx/default.conf
sed "s/MINIKUBE_IP/$MINIKUBE_IP/g" ./srcs/phpmyadmin/config_format.inc.php > ./srcs/phpmyadmin/config.inc.php
sed "s/MINIKUBE_IP/$MINIKUBE_IP/g" ./srcs/wordpress/wordpress_format.sql > ./srcs/wordpress/wordpress.sql
sed "s/MINIKUBE_IP/$MINIKUBE_IP/g" ./srcs/ftps/vsftpd_format.conf > ./srcs/ftps/vsftpd.conf

echo -e "\033[31mmetalLB\033[0m"
kubectl apply -f ./srcs/metallb/metallb.yaml

#nginx
echo -e "\033[31mnginx\033[0m"
docker build -t nginx ./srcs/nginx/ > /dev/null
kubectl apply -f ./srcs/nginx/nginx.yaml

#ftps
echo -e "\033[31mftps\033[0m"
docker build -t ftps ./srcs/ftps/ > /dev/null
kubectl apply -f ./srcs/ftps/ftps.yaml

#mysql
echo -e "\033[31mmysql\033[0m"
docker build -t mysql ./srcs/mysql/ > /dev/null
kubectl apply -f ./srcs/mysql/mysql.yaml

#phpmyadmin
echo -e "\033[31mphpmyadmin\033[0m"
docker build -t phpmyadmin ./srcs/phpmyadmin/ > /dev/null
kubectl apply -f ./srcs/phpmyadmin/phpmyadmin.yaml

#wordpress
echo -e "\033[31mwordpress\033[0m"
docker build -t wordpress ./srcs/wordpress/ > /dev/null
kubectl apply -f ./srcs/wordpress/wordpress.yaml

#influxdb
echo -e "\033[31minfluxdb\033[0m"
docker build -t influxdb ./srcs/influxdb/ > /dev/null
kubectl apply -f ./srcs/influxdb/influxdb.yaml

#telegraf
echo -e "\033[31mtelegraf\033[0m"
docker build -qt telegraf ./srcs/telegraf/ > /dev/null
kubectl apply -f ./srcs/telegraf/telegraf.yaml

#grafana
echo -e "\033[31mgrafana\033[0m"
docker build -t grafana ./srcs/grafana/ > /dev/null
kubectl apply -f ./srcs/grafana/grafana.yaml
