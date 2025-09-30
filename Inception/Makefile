# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lizhang <lizhang@student.42.fr>              +#+                      #
#                                                    +#+                       #
#    Created: 2025/09/12 23:41:49 by lizhang       #+#    #+#                  #
#    Updated: 2025/09/26 14:50:28 by lizhang       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

include ./srcs/.env
export


DOCKER_COMPOSE = docker compose -f ./srcs/docker-compose.yml
CERT_DIR := ./srcs/certs

all: certs up

certs:
	mkcert -install
	mkdir -p "$(CERT_DIR)"
	@if [ ! -f $(CERT_DIR)/$(DOMAIN_NAME).crt ] || [ ! -f $(CERT_DIR)/$(DOMAIN_NAME).key ]; then \
	mkcert -install && \
	mkcert -cert-file $(CERT_DIR)/$(DOMAIN_NAME).crt \
	       -key-file $(CERT_DIR)/$(DOMAIN_NAME).key \
	       $(DOMAIN_NAME); \
	else echo "Certificates already exist, not generating again."; \
	fi
# install mkcert. ssl is needed for chrome/firefox to access the custom domain, otherwise chrome/firefox doesn't recognize the message
# mkcert also altomatically sets the custom domain to Common Name so the domain matches the domain in the certificate

up:
	sudo mkdir -p "/home/"$(LOGIN)"/data/mariadb"
	sudo mkdir -p "/home/"$(LOGIN)"/data/wordpress"
	@$(DOCKER_COMPOSE) up -d
# the @ sign supresses the prints coming from the make process
# -f specify the path to the compose file
# -d run the docker in detached mode, which means it doesn't block the terminal while doing so. It makes it possible to start multiple docker containers quickly.

down:
	@$(DOCKER_COMPOSE) down
# down stops containers and removes them, plus networks and optionally volumes/images

stop:
	@$(DOCKER_COMPOSE) stop
# stop stops containers without wiping the current state

kill:
	@$(DOCKER_COMPOSE) kill
# kill the docker immediately, no saving state and can possibly corrupt related db volume

start:
	@$(DOCKER_COMPOSE) start
# start, unlike up, is the continuation of a allready built docker that has been stopped

build:
	@$(DOCKER_COMPOSE) up -d --build
# rebuild docker so the containers are updated, volumes will stay the same

clean:
	@ $(DOCKER_COMPOSE) down -v && \
	docker rm $$(docker ps -qa) 2>/dev/null || true && \
	docker rmi $$(docker images -qa) 2>/dev/null || true && \
	docker volume rm $$(docker volume ls -q) 2>/dev/null || true && \
	docker network rm $$(docker network ls -q) 2>/dev/null || true
	@rm $(CERT_DIR)/$(DOMAIN_NAME).crt $(CERT_DIR)/$(DOMAIN_NAME).key 2>/dev/null || true
	@sudo rm -rf /home/lizhang/data/wordpress/*
	@sudo rm -rf /home/lizhang/data/mariadb/*

deep_clean: clean
	@docker builder prune -a -f && \
	docker system prune -a --volumes -f 
# clean all cached because docker will use what is allready available to avoid doing the same again

rebuild: clean certs
	@$(DOCKER_COMPOSE) build
	@$(DOCKER_COMPOSE) up -d
# rebuild but recreate the volumes as well, loose all db stored data

.PHONY: all certs clean rebuild deep_clean up down stop kill start build