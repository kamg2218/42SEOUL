mysql_install_db -u root > /dev/null
mysqld -u root --bootstrap < ./init
mysqld -u root
