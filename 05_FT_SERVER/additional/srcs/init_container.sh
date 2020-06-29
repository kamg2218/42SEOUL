service mysql start

#echo "[mysqld]" >> etc/mysql/my.cnf
#echo "skip-grant-tables" >> etc/mysql/my.cnf

echo "CREATE DATABASE wordpress;" | mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'root'@'localhost' WITH GRANT OPTION;" | mysql -u root --skip-password
echo "update mysql.user set plugin='mysql_native_password' where user='root';" | mysql -u root --skip-password
echo "FLUSH PRIVILEGES;" | mysql -u root --skip-password

echo "ALTER USER 'root'@'localhost' IDENTIFIED BY 'hyoon';" | mysql -u root -p

service php7.3-fpm start
service nginx start

bash
