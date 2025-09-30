#!/bin/bash
set -e

# DB_HOST=$(echo "$WP_DB_HOST" | cut -d: -f1)
# DB_PORT=$(echo "$WP_DB_HOST" | cut -d: -f2)

echo "Waiting for MariaDB to be ready..."

MAX_RETRIES=20

for i in $(seq 1 $MAX_RETRIES); do
  if mysqladmin ping -hmariadb -u"$WP_DB_USER" -p"$WP_DB_PASSWORD" --silent; then
    echo "Database is ready!"
    break
  fi
  echo "Waiting for database... ($i/$MAX_RETRIES)"
  sleep 2
  if [ "$i" -eq "$MAX_RETRIES" ]; then
    echo "MariaDB did run after $MAX_RETRIES attempts. Exiting."
    exit 1
  fi
done

# continue with wp-config.php creation and installation

# If wp-config.php does not exist, create it
if [ ! -f /var/www/html/wp-config.php ]; then
  echo "Creating wp-config.php..."
  wp config create \
    --path=/var/www/html \
    --dbname="$WP_DB_NAME" \
    --dbuser="$WP_DB_USER" \
    --dbpass="$WP_DB_PASSWORD" \
    --dbhost="$WP_DB_HOST" \
    --allow-root \
    --skip-check \
    --allow-root
fi

# Continue with WordPress install if not already done
if ! wp core is-installed --path=/var/www/html --allow-root; then
  echo "Running WordPress installation..."
  wp core install \
    --path=/var/www/html \
    --url="$WP_SITEURL" \
    --title="My WordPress Site" \
    --admin_user="$WP_ADMIN_USER" \
    --admin_password="$WP_ADMIN_PASSWORD" \
    --admin_email="$WP_ADMIN_EMAIL" \
    --allow-root
fi

# Create another WordPress users if they don't exist
if ! wp user get "$WP_USER2" --allow-root >/dev/null 2>&1; then
  wp user create "$WP_USER2" "$WP_USER2_EMAIL" \
    --role="$WP_USER2_ROLE" \
    --user_pass="$WP_USER2_PASSWORD" \
    --allow-root
fi

# Start PHP-FPM in foreground
exec php-fpm8.2 -F
