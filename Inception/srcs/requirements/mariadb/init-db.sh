#!/bin/bash
set -e

# start MariaDB temporarily first
# this is necessary because Mariadb needs to set up the db without interference with wordpress that will try to write to the db
# that is also why wordpress need to wait for mariadb to be ready

mysqld_safe --skip-networking &
pid="$!"
# mysqld_safe instead of just mysqld (the command prompt for mysql) because it restart if fail so is safer and generally used in init stage

MAX_RETRIES=20

for i in $(seq 1 $MAX_RETRIES); do
  if mysqladmin ping --silent; then
    break
  fi
  echo "Waiting for MariaDB to start... (try/retry $i/$MAX_RETRIES)"
  sleep 2
  if [ "$i" -eq "$MAX_RETRIES" ]; then
    echo "MariaDB fails to start. Exiting."
    exit 1
  fi
done
# if mariadb hasn't finished loading, the following command would cause an error

# Secure root user and create WordPress database + user, this makes the custom admin user possible
mysql -uroot -p${MYSQL_ROOT_PASSWORD} <<-EOSQL
    ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';
    CREATE DATABASE IF NOT EXISTS \`${MYSQL_DATABASE}\` CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci;
    CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
    GRANT ALL PRIVILEGES ON *.* TO '${MYSQL_USER}'@'%' WITH GRANT OPTION;
    FLUSH PRIVILEGES;
EOSQL
# by default root@localhost doesn't have a password, which makes it inaccessible for outside the container
# CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci makes it possible for the tables to accept emojis, because wordpress by default supports that
# WITH GRANT OPTION means the user can grant permission to other users
# flush privileges is needed to refresh the tables so the changes have taken place 

# Stop temporary MariaDB instance
mysqladmin -uroot -p${MYSQL_ROOT_PASSWORD} shutdown
wait "$pid"

# Bring MariaDB up in foreground
exec mysqld_safe --bind-address=0.0.0.0
