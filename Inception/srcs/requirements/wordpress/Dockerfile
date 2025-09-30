FROM debian:12.12

# set environment variables
ENV WP_VERSION=6.8.2

# install php-fpm, PHP, and required extensions
RUN apt-get update && apt-get install -y \
    php-fpm \
    php-mysql \
    php-xml \
    php-curl \
    php-gd \
    php-mbstring \
    php-zip \
    curl \
    wget \
    tar \
    ca-certificates \
    mariadb-client \
    && rm -rf /var/lib/apt/lists/*
# the last step is just a cleaning command, improves speed

# Symlink versioned binary to generic name
RUN ln -s /usr/sbin/php-fpm8.2 /usr/sbin/php-fpm

# download and extract WordPress
WORKDIR /var/www/html
RUN wget https://wordpress.org/wordpress-6.8.2.tar.gz \
    && tar -xzf wordpress-6.8.2.tar.gz --strip-components=1 \
    && rm wordpress-6.8.2.tar.gz

# set ownership
RUN chown -R www-data:www-data /var/www/html

# Install WP-CLI, so we can create the 2 users with commands here, alternative is creating it in the WP UI
RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
    && chmod +x wp-cli.phar \
    && mv wp-cli.phar /usr/local/bin/wp

# Copy create user script
COPY create_users.sh /create_users.sh
RUN chmod +x /create_users.sh

EXPOSE 9000

# Configure php-fpm to listen on TCP port 9000 instead of a Unix socket
RUN sed -i 's|^listen = .*|listen = 0.0.0.0:9000|' /etc/php/8.2/fpm/pool.d/www.conf

# run php-fpm in foreground
CMD ["php-fpm8.2", "-F"]

# Use the entrypoint script
ENTRYPOINT ["/create_users.sh"]

