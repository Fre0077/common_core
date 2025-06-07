FROM debian:11

# Evita interazione durante l'installazione
ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && \
    apt-get install -y mariadb-server && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

RUN rm -rf /etc/mysql/mariadb.conf.d/50-server.cnf
COPY ./50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

# Copia lo script di inizializzazione
COPY setup.sh /setup.sh
RUN chmod +x /setup.sh

EXPOSE 3306

ENTRYPOINT ["sh", "setup.sh"]
CMD ["mysqld"]
