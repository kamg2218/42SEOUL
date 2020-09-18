service mysql restart

echo "CREATE DATABASE wordpress;" | mysql -u root --skip-password
echo "create user 'hyoon'@'%' identified by 'hyoon';" | mysql -u root --skip-password
echo "grant all privileges on *.* to 'hyoon'@'%';" | mysql -u root --skip-password

service php7.3-fpm restart
service nginx restart

bash
