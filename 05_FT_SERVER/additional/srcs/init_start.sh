#openssl

apt-get -y install openssl vim
openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Lee/CN=localhost" -keyout localhost.dev.key -out localhost.dev.crt

mv localhost.dev.crt etc/ssl/certs
mv localhost.dev.key etc/ssl/private
chmod 600 etc/ssl/certs/localhost.dev.crt etc/ssl/private/localhost.dev.key

#php-fpm
apt-get -y install php-fpm

mv default etc/nginx/sites-available/default
mv phpinfo.php var/www/html/

#mysql
apt-get -y install mariadb-server php-mysql

#phpmyadmin
apt-get -y install wget

wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz

tar -xvf phpMyAdmin-5.0.2-all-languages.tar.gz

mv phpMyAdmin-5.0.2-all-languages phpmyadmin
mv phpmyadmin var/www/html

cp -rp var/www/html/phpmyadmin/config.sample.inc.php var/www/html/phpmyadmin/config.inc.php
mv config.inc.php var/www/html/phpmyadmin/config.inc.php

#wordpress
wget https://wordpress.org/latest.tar.gz
tar -xvf latest.tar.gz
mv wordpress/ var/www/html/
chown -R www-data:www-data var/www/html/wordpress
cp var/www/html/wordpress/wp-config-sample.php var/www/html/wordpress/wp-config.php
mv wp-config.php var/www/html/wordpress/wp-config.php

#autoindex on
rm var/www/html/index.nginx-debian.html

#mysql password
bash init_container.sh
