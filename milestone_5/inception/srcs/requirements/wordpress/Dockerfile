FROM debian:11

RUN apt-get update -y && apt-get upgrade -y
RUN apt-get install -y php \
	php-fpm \
    php-common \
    php-mysql \
    php-gmp \
    php-curl \ 
    php-intl \
    php-mbstring \
	php-xmlrpc \
    php-gd \
    php-xml \
    php-cli \
    php-zip \
    php-soap \
    php-imap \
    wget \
    curl \
	vim \
    openssl \
    sendmail \ 
    mariadb-client \
    procps;

RUN sed -i 's|listen = .*|listen = 9000|' /etc/php/7.4/fpm/pool.d/www.conf

# Install WP-CLI
RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
    chmod +x wp-cli.phar && \
    mv wp-cli.phar /usr/local/bin/wp

RUN mkdir -p /run/php/

COPY ./tools/setup.sh /
RUN chmod 777 /setup.sh
WORKDIR /var/www/html/

EXPOSE 9000 21

ENTRYPOINT ["sh", "/setup.sh"]