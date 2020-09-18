# FT_SERVER

## 1. Debian:buster

   * docker pull debian:buster - debian 이미지 다운
   * docker run -it -p 80:80 -p 443:443 debian:buster
   * docker run -it debian - debian:latest로 최신 버전의 데비안을 사용한다.
   * docker --name [container name] run -it debian:buster - 만드는 컨테이너의 이름 설정
   * -i, -interactive : keep STDIN open even if not attached
   * -t, -tty : allocate a pseudo-TTY
   * -p, -publish list : 호스트와 컨테이너의 포트를 연결한다.
   * -rm : 프로세스 종료시에 컨테이너 자동 제거

## 2. Nginx

   * 데비안에서는 패키지 관리자 apt-get 사용한다.
   * apt-get update
   * apt-get -y upgrade - -y : yes for all
   * apt-get -y install nginx
   * service nginx start
   * service nginx status : 상태 확인
   * 새로운 terminal 창에 curl localhost - 로컬호스트 창의 html 문법이 나욘다.

## 3. SSL 인증서 만들기

### Self-signed SSL 인증서

   * apt-get -y install openssl vim
   * openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Lee/CN=localhost" -keyout localhost.dev.key -out localhost.dev.crt"
   * mv localhost.dev.crt etc/ssl/certs/
   * mv localhost.dev.key etc/ssl/private/
   * chmod 600 ect/ssl/certs/localhost.dev.crt etc/ssl/private/localhost.dev.key
   
   * CN : common name, 인증서 고유 이름
   * O  : organization, 기관명
   * OU : organization unit, 회사의 팀
   * L  : city/locality, 시/도
   * S  : state/county/region, 구/군
   * ST : street, 상세주소
   * C  : country, 국가 코드, 한국 : KR
   * .csr : 인증 사인 요청파일
   * .crt : 인증서 파일
   * -days : 유효 일수
   * -nodes : 생략시, 재부팅할때 암호 입력해야한다.
   
### CSR 을 만들어서 CA에 요청하여 발급

   * CA(Certificate Authority)는 인증서의 역할을 하는 민간기관을 말한다.
   * 인증서는 클라이언트가 접속한 서버가 클라이언트가 의도한 서버가 맞는지를 보장하는 역할을 한다.
   * 공인된 CA가 제공하는 인증서가 아닌, 사설 인증기관의 CA를 사용하는 경우 브라우저는 경고를 출력한다.
   
## 4. Nginx 에 SSL 설정

   * vi etc/nginx/sites-available/default
   
    </
       server {
                listen 80 default_server;
                listen [::]:80 default_server;
        }

        server {
                listen 443;

                ssl on;
                ssl_certificate /etc/ssl/certs/localhost.dev.crt;
                ssl_certificate_key /etc/ssl/private/localhost.dev.key;

                root /var/www/html;

                index index.html index.htm index.nginx-debian.html;

                ...	
        }
    />
    
   * service nginx reload / service nginx restart

## 5. php-fpm 설치

   * PHP FastCGI Process Manager
   * Apache의 경우, apache용 php모듈을 사용하지만, nginx의 경우, 모듈이 없어 php-fpm을 설치하여 사용한다.
   * 웹서버에서 요청을 받아 외부 프로그램으로 전달하면, 외부 프로그램은 프로그램 파일을 읽어 html로 반환하는 단계를 거치는 것을 CGI라고 한다.
   * 동적인 페이지 구현을 위해 php-fpm 설치가 필요하다.

   * apt-get -y install php-fpm
   * sites-available : 설정 파일
   * sites-enabled   : 실행시킬 파일들을 symlink로 연결해서 넣는다.
   * nginx.conf      : sites-enabled에 있는 파일을 호출하는 파일, 서버 실행에 관한 정보
   * vi /etc/nginx/sites-available/default

    FROM
    </
        #location ~ \.php$ {
        #	include snippets/fastcgi-php.conf;
        \#
        #	# With php-fpm (or other unix sockets):
        #	fastcgi_pass unix:/var/run/php/php7.3-fpm.sock;
        #	# With php-cgi (or other tcp sockets):
        #	fastcgi_pass 127.0.0.1:9000;
        #}
    />
    TO
    </
        location ~ \.php$ {
        include snippets/fastcgi-php.conf;
        \#
        #	# With php-fpm (or other unix sockets):
        fastcgi_pass unix:/var/run/php/php7.2-fpm.sock;
        #	# With php-cgi (or other tcp sockets):
        #	fastcgi_pass 127.0.0.1:9000;
        }
    />

   * PHP를 사용하는 경우, 
   * index index.html index.htm index.nginx-debian.html; 
   * 뒤에 index.php를 추가해야한다. (맨 앞에 쓰면 오류 발생! 맨 뒤에 추가해야한다.)
   * service php7.3-fpm start
   * service php7.3-fpm status

### phpinfo()로 연동 확인!
   
   * cd /var/www/html
   * vi phpinfo.php
   * <?php phpinfo(); ?> 저장
   * service nginx reload / service nginx restart
   * 오류 발생시, cat /var/log/nginx/error.log로 오류내역 확인
   * localhost에서 /phpinfo.php로 접속했을 때, phpinfo페이지가 나오는 지 확인

   * Chrome에서는 404 ERROR가 발생하는데 Safari에서는 오류없이 확인된다. 왜??

## 6. MariaDB 설치

   * apt-get -y install mariadb-server php-mysql
   * 데비안 9부터는 MariaDB를 디폴트로 사용하고, 데비안 buster는 10이므로 mariadb 설치

## 7. phpMyadmin 설치

   * wget 으로 직접 다운로드한다.
   * 압축을 해제하여 폴더명을 phpmyadmin으로 변경한 뒤, var/www/html로 위치 변경한다.

   * apt-get install -y wget
   * wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz
   * tar -xvf phpMyAdmin-5.0.2-all-languages.tar.gz
   * mv phpMyAdmin-5.0.2-all-languages phpmyadmin
   * mv phpmyadmin /var/www/html/
   
### phpmyadmin 설정

   * phpmyadmin/config.sample.inc.php 파일을 복사하여 config.inc.php 만든다.
   * config.inc.php에 블로피시 암호를 만들어 넣는다.
   * 블로피시(blowfish) 암호 ? 키 방식의 대칭형 블록 암호 / http://www.passwordtool.hu/blowfish-password-hash-generator
   * create_tables.sql 을 가져와서 phpMyAdmin을 위한 테이블 만든다.

   * cp -rp var/www/html/phpmyadmin/config.sample.inc.php var/www/html/phpmyadmin/config.inc.php
   * vim var/www/html/phpmyadmin/config.inc.php
   * $cfg['blowfish_secret'] = '이 부분에 넣는다';
   * service nginx reload
   * service mysql start
   * service php7.3-fpm restart
   * mysql < var/www/html/phpmyadmin/sql/create_tables.sql -u root --skip-password
   * mysqladmin -u root -p password
   * 기존 패스워드 없으니 엔터 입력
   * 새 패스워드 입력
   * 한 번 더 입력
   * mysql
   * show databases;
   * CREATE DATABASE IF NOT EXISTS wordpress;
   * show databases;
   * exit
   * service mysql start --> localhost/phpmyadmin 에서 로그인해보기!

#### mysqli::real_connect(): (HY000/1698): Access denied for user 'root'@'localhost' 오류 발생!!
    
    MySQL 5.7, MariaDB 10.1 이후 버전은 보안상 root 계정은 터미널에서만 접속할 수 있고, root를 제외한 사용자 계정으로 phpMyAdmin에 접속할 수 있다.
    
    새로운 사용자를 만들어, 권한을 부여하여 root 계정처럼 사용할 수 있다.
    
   * reference : https://extrememanual.net/33257

   * 새로운 계정 만들고, 권한 부여하기!
   * create user '아이디'@'%' identified by '비밀번호';
   * grant all privileges on *.* to '아이디'@'%';
   * 
   * 보안을 포기하고, 권한을 root 와 동등하게 부여하기
   * UPDATE mysql.user SET Grant_priv='Y', Super_Priv='Y' WHERE user='아이디';
   * FLUSH PRIVILEGES;


## 8. Wordpress 설치

   * wget https://wordpress.org/latest.tar.gz
   * tar -xvf latest.tar.gz
   * mv wordpress var/www/html
   * chown -R www-data:www-data /var/www/html/wordpress
   
   * chown : 리눅스에서 소유자를 변경하는 커맨드
   * www-data : 우분투에서 apache, php 실행시 수정이 가능한 권한

### wordpress 설정

    cp var/www/html/wordpress/wp-config-sample.php var/www/html/wordpress/wp-config.php 

    vim var/www/html/wordpress/wp-config.php 

    아래 부분을 내용에 맞게 바꿔준다.
    
    단, user_id, password는 phpmyadmin으로 로그인하는 id, pwd와 같아야 한다.

    // ** MySQL settings - You can get this info from your web host ** //

    /** The name of the database for WordPress */

    define( 'DB_NAME', 'wordpress' );

    /** MySQL database username */

    define( 'DB_USER', 'root' );

    /** MySQL database password */

    define( 'DB_PASSWORD', 'root' );

    /** MySQL hostname */

    define( 'DB_HOST', 'localhost' );

    /** Database Charset to use in creating database tables. */

    define( 'DB_CHARSET', 'utf8' );

    /** The Database Collate type. Don't change this if in doubt. */
    
    define( 'DB_COLLATE', '' );
    
## 9. Autoindex 추가하기

    server_name _;

    location / {

    # First attempt to serve request as file, then

    # as directory, then fall back to displaying a 404.
	
    autoindex on;
	
    try_files $uri $uri/ =404;
    
    }


   * /var/www/html/ 내에 있는 내용이 순서대로 나타난다.
   * phpinfo.php는 지우는 것이 좋다!

## 10. url redirection

   * http 주소를 https 주소로 들어오도록 리다이렉션을 시킨다.
   * http 상태코드 : 100번대 - 정보 / 200번대 - 성공 / 300번대 - 리다이렉션 / 400번대 - 클라이언트 오류 / 500번대 - 서버 오류
   
   * vi etc/nginx/sites-available/default
   
    server {
	
    listen 80 default_server;
	
    listen [::]:80 default_server;

	return 301 https://$host$request_uri;

    }
    
    
## 11. Reference

   [42wiki](https://yeosong1.github.io/ftserver-%ED%92%80%EC%9D%B4%EA%B8%B0%EB%A1%9D)
    
   [Manual Factory](https://www.manualfactory.net/10903)
    
