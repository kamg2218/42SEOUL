## ft_services

### virtual Box

minikube start --driver=virtualbox

드라이버를 virtualbox로 사용하는 이유는 외부 아이피를 가져와서 컨테이너들과 연결하기 위해서이다.


### eval $(minikube docker-env)

위의 명령어를 입력하여, 앞으로의 컨테이너 관련 명령어가 docker에서 적용되는 것이 아닌,

minikube에서 적용되도록 바꾸어 준다.


### MINIKUBE_IP=$(minikube ip)

환경변수로 MINIKUBE_IP 변수값을 minikube ip 값으로 저장한다. 


### metalLB

표준 라우팅 프로토콜을 사용하는 쿠버네티스 클러스터를 위한 Load Balancer 이다.


https://boying-blog.tistory.com/16 //metallb 참고

https://metallb.universe.tf/installation/ //metallb 참고

~~~

    kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/namespace.yaml
    kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/metallb.yaml
    kubectl create secret generic -n metallb-system memberlist --from-literal=secretkey="$(openssl rand -base64 128)"
    kubectl apply -f ./srcs/metallb/config.yaml

~~~


### nginx

#### Dockerfile

FROM alpine:3.12  - 3.12 버전을 사용해야 버전 이슈가 발생하지 않는다.(DNS Lookup error 이슈가 있다.)

RUN apk update && apk upgrade - 업데이트 및 업그레이드를 시킨다.

RUN apk add nginx - apt-get에서 install 명령어는 add로 대체된다.

RUN apk add openssl vim - openssl과 vim을 설치한다.

RUN openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Lee/CN=localhost" -keyout localhost.dev.key -out localhost.dev.crt - key 생성하기

RUN mv localhost.dev.crt etc/ssl/certs/ - 파일 이동하기

RUN mv localhost.dev.key etc/ssl/private/ - 파일 이동하기

RUN chmod 600 etc/ssl/certs/localhost.dev.crt etc/ssl/private/localhost.dev.key - 권한 변경하기

RUN mkdir /run/nginx - 데비안과 다르게 필요한 디렉토리가 자동적으로 생성되지 않는다.

RUN apk add openssh - openssh 설치

RUN sed 's/#PermitRootLogin prohibit-password/PermitRootLogin yes/' -i /etc/ssh/sshd_config - 파일 내용 수정

RUN echo 'root:hyoon' | chpasswd - 비밀번호 변경

RUN ssh-keygen -f /etc/ssh/ssh_host_rsa_key -N '' -t rsa - 키 생성

RUN ssh-keygen -f /etc/ssh/ssh_host_dsa_key -N '' -t dsa - 키 생성

RUN mkdir -p /var/run/sshd

COPY ./nginx.conf ./etc/nginx/nginx.conf - default 파일이 생성되지 않으므로 nginx.conf를 수정해준다.

COPY ./index.html ./var/www/html/index.html - index 파일을 만들어줘야한다.

COPY ./sshd_config ./etc/ssh/sshd_config - 파일 변경하기

COPY ./start.sh ./start.sh - 배시 파일 복사

EXPOSE 22 - 22 포트에 연결한다.

EXPOSE 80 - 80 포트에 연결한다.

EXPOSE 443 - 443 포트에 연결한다.

ENTRYPOINT ["sh", "./start.sh"] 

#### start.sh

/bin/sbin/sshd - sshd 실행하기! (ssh를 실행하지 않아서 liveness probe 가 자꾸 refused되어 파드가 지속적으로 Error 발생되고, 컨테이너가 재실행되었다.)

nginx -g 'daemon off;' - daemon off 로 nginx 실행하기(nginx를 foreground로 실행한다. 하나의 서버는 하나의 서비스만 실행한다.)

#### nginx.conf

~~~

    access_log /var/log/nginx/access.log;
        server {
            listen 80 default_server;
            listen [::]:80 default_server;
            root /var/www/html;
            index index.html index.htm;
            server_name _;
        location / {
            return 301 https://$host$request_uri;
            }
        }
        server {
            # ssl on;
            listen 443 ssl;
            listen [::]:443 ssl;
            
            ssl_certificate /etc/ssl/certs/localhost.dev.crt;
            ssl_certificate_key /etc/ssl/private/localhost.dev.key;

            root /var/www/html;
            index index.html index.htm;
            client_max_body_size 32m;
            location / {
                try_files $uri $uri/ =404;
                }
            location /wordpress {
                return 307 http://$host:5050;
            }
            location /phpmyadmin {
                ERROR~!!!!!!
            }
            location /index.php {
                return 301 http://$host/phpmyadmin;
            }
        }

~~~

위의 내용을 추가하여 redirection 설정을 해준다.

#### ssh

secure shell protocol, ssh

네트워크 프로토콜 중 하나로 컴퓨터와 컴퓨터가 인터넷과 같은 공공 네트워크를 통해 서로 통신을 할 때 보안적으로 안전하게 통신을 하기위해 사용하는 프로토콜

apk add openssh

PermitRootLogin prohibit-password --> yes : 설정을 바꾸어야 로그인이 가능하다.

https://zetawiki.com/wiki/SSH_%EC%A0%91%EC%86%8D_%EA%B0%80%EB%8A%A5%ED%95%9C_%EC%95%8C%ED%8C%8C%EC%9D%B8_%EB%8F%84%EC%BB%A4_%EC%9D%B4%EB%AF%B8%EC%A7%80_%EB%B9%8C%EB%93%9C //ssh 설치하기 연습

https://man.openbsd.org/sshd_config#PermitRootLogin //ssh 설정파일

#### nginx.yaml

##### pod vs service

파드는 쿠버네티스에서 생성하고 관리할 수 있는 배포 가능한 가장 작은 컴퓨팅 단위이다.

하나 이상의 컨테이너의 그룹으로 여러 개의 컨테이너를 실행할 수 있다.

서비스는 파드 집합에서 실행 중인 응용프로그램을 네트워크 서비스로 노출하는 추상화 방법을 말한다.

쿠버네티스는 파트에게 고유한 IP 주소와 파드 집합에 대한 단일 DNS 명을 부여하고, 그들 간에 로드-밸런스를 수행한다.


##### imagePullPolicy: Never

imagePullPolicy 값이 Never 또는 IfNotPresent 인 경우, 로컬 이미지만 사용한다.

만약, Always 인 경우, 각 이미지를 특정 저장소에서 가져온다.

https://kubernetes.io/docs/concepts/containers/images/ //imagePullPolicy


##### externalTrafficPolicy

Cluster : 밸런싱은 노드뿐만 아니라 요청을 분산하기위한 포드의 수를 고려하고, 불균형을 방지하기위해 쿠버네티스는 클러스터 내에서 밸런싱을 수행한다.

Local : 로컬은 패킷이 포드에 도착하면 큐브 프록시는 클러스터의 다른 노드에 사용 가능한 포드가 더 많고, 로드된 것이 적더라도 오직 동일한 노드 포드 내에서만 로드를 분산한다.

https://medium.com/pablo-perez/k8s-externaltrafficpolicy-local-or-cluster-40b259a19404 //externalTrafficPolicy

##### annotations

임의의 식별되지 않는 metadata를 객체에 첨부할 수 있다.

https://kubernetes.io/docs/concepts/overview/working-with-objects/annotations/ //annotations

##### liveness probe

~~~

    livenessProbe:
      exec:
        command:
        - cat
        - /tmp/healthy
      initialDelaySeconds: 5
      periodSeconds: 5

~~~

periodSeconds 는 5초마다 liveness probe를 실행하는 것을 의미한다.

또한, initialDelaySeconds 는 첫 probe를 실행하기 전에 5초간 기다린다는 것을 의미한다.

응용프로그램은 오랜시간동안 동작하고, 갑자기 연결이 끊어지거나 다시 시작하는 것 말고는 복구할 방법이 없는 경우가 있다.

liveness probe는 이런 경우를 감지하고 다시 연결시키도록 한다.

probe를 실행하기위해 cat /tmp/healthy 를 실행하고, 만약, 연결이 성공한 경우, 0을 반환한다.

만약, 연결에 실패한 경우, 0이 아닌 값을 반환하고, 컨테이너를 죽이고 다시 시작한다.

https://kubernetes.io/docs/tasks/configure-pod-container/configure-liveness-readiness-startup-probes/ //liveness probe

### wordpress

도커에 워드프레스를 설치하는 경우, 시스템이 리눅스 기반이 아닌 경우, 가상환경을 설치하여 리눅스 환경을 만들어야 한다.

#### Dockerfile

FROM alpine:3.12  - 모든 파일에 기본적으로 alpine linux를 설치해야한다.

RUN apk update && apk upgrade - 업데이트 및 업그레이드 하기

RUN apk add wget - wget 설치하기

RUN apk add php7 php7-fpm php7-opcache php7-gd php7-mysqli php7-zlib php7-curl php7-mbstring php7-json php7-session - php 설치하기

RUN mkdir -p /run/nginx

RUN wget https://wordpress.org/latest.tar.gz - wordpress 설치하기

RUN tar -xvf latest.tar.gz  - 압출파일 풀기

RUN mv wordpress /etc/ - wordpress 디렉토리를 root로 이동시키기

RUN rm -rf var/cache/apk/\*  - cache 파일 삭제하기

COPY nginx.conf /etc/nginx/nginx.conf

COPY wp-config.php /etc/wordpress/

COPY ./start.sh ./start.sh

EXPOSE 5050

ENTRYPOINT ["sh", "./start.sh"]

#### start.sh

nginx -g 'daemon off;'

php-fpm7

php -S 0.0.0.0:5050 -t /etc/wordpress/


#### wp-config.php

DB 설정 바꾸기!

define( 'DB_NAME', 'wordpress' );

define( 'DB_USER', 'hyoon' );

define( 'DB_PASSWORD', 'hyoon' );

define( 'DB_HOST', 'mysql-service' );

define( 'DB_CHARSET', 'utf8' );

define( 'DB_COLLATE', '' );

### MySQL

#### Dockerfile

FROM alpine:3.12

RUN apk update && apk upgrade

RUN apk add mysql mysql-client

RUN mkdir -p /run/mysqld

COPY ./my.cnf /etc/my.cnf

COPY ./init .

COPY ./start.sh .

EXPOSE 3306

ENTRYPOINT ["sh", "/tmp/start.sh"]


#### my.cnf

[mysqld]

user=root

port=3306

datadir=/var/lib/mysql

log-bin=/var/lib/mysql/mysql-bin

bind-address=0.0.0.0

skip-networking=0

#### start.sh

mysql_install_db --user=root

mysqld --user=root --bootstrap < ./init

mysqld --user=root


#### mysql.yaml

### phpmyadmin

#### Dockerfile



### ftps

#### Dockerfile

