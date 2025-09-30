FROM debian:12.12

# set environment variables
ENV DEBIAN_FRONTEND=noninteractive
ENV WP_version=6.8.2

# install Nginx, php-fpm, and required extensions
RUN apt-get update && apt-get install -y --no-install-recommends \
    nginx \
    wget \
    libnss3-tools \
    ca-certificates \
    gettext-base \
    && rm -rf /var/lib/apt/lists

RUN mkdir -p /etc/nginx/certs \
    && mkdir -p /var/log/nginx \
    && mkdir -p /var/www/html
# create directory for certs

COPY conf.d/default.conf.template /etc/nginx/conf.d/default.conf.template

# Replace domain in nginx config, default.config cannot see the environment variables
RUN envsubst '$DOMAIN_NAME' < /etc/nginx/conf.d/default.conf.template \
    > /etc/nginx/conf.d/default.conf

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]

