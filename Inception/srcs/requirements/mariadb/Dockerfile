FROM debian:12.12

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y --no-install-recommends \
    mariadb-server \
    mariadb-client \
    && rm -rf /var/lib/apt/lists/*

RUN mkdir -p /var/lib/mysql /var/run/mysqld /docker-entrypoint-initdb.d \
    && chown -R mysql:mysql /var/lib/mysql /var/run/mysqld \
    && chmod u=rwx,g=rx,o=rx /var/run/mysqld
# root creates the files, but mysql is the user and need to write to the files, 
# thus need to change mysql as the owner of the files, with chmod permission write permission is not given to the users and others to prevent security concerns 
# /docker-entrypoint-initdb.d is the directory where init-db.sh is copied to

# Copy entrypoint script
COPY init-db.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/init-db.sh

EXPOSE 3306
# docker compose know this container has 3306 available for connection so set wordpress to send package to this port but in mariadb container, the program by default blocks connection from other sources than local which is 127.0.0.1

ENTRYPOINT ["init-db.sh"]
CMD ["mysqld_safe", "--bind-address=0.0.0.0"]

# --bind-address=0.0.0.0 tells mariadb to listen to all sources on the network
# if we don't have this line, it will only listen to processes in the same container, WordPress would be blocked

