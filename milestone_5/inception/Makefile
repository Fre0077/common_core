# Variables
COMPOSE_FILE = docker-compose.yml
PROJECT_NAME = inception

all: help

# Default target
.PHONY: help
help:
	@echo "Available commands:"
	@echo "  make up    - Start all services"
	@echo "  make down  - Stop services and clean volumes"
	@echo "  make re    - Restart everything (down + up)"
	@echo "  make logs  - Show logs of all services"
	@echo "  make clean - Clean everything (containers, volumes, images)"

# Start all services
.PHONY: up
up:
	@echo "🚀 Starting Inception services..."
	docker-compose up --build
	@echo "✅ Services started successfully!"
	@echo "🌐 Access your site at: https://fde-sant.42.fr"

# Stop services and clean volumes
.PHONY: down
down:
	@echo "🛑 Stopping services..."
	docker-compose -f $(COMPOSE_FILE) down
	@echo "🗑️  Removing volumes..."
	docker volume prune -f
	@echo "🧹 Cleaning up data directories..."
	sudo rm -rf ~/data/wp/* ~/data/db/* 2>/dev/null || true
	@echo "✅ Cleanup completed!"

# Restart everything
.PHONY: re
re: down up
	@echo "🔄 Restart completed!"

# Show logs
.PHONY: logs
logs:
	docker-compose -f $(COMPOSE_FILE) logs -f

# Deep clean everything
.PHONY: clean
clean:
	@echo "🧹 Deep cleaning..."
	docker-compose -f $(COMPOSE_FILE) down --remove-orphans
	docker system prune -af --volumes
	sudo rm -rf ~/data 2>/dev/null || true
	@echo "✅ Deep clean completed!"

# Check status
.PHONY: status
status:
	@echo "📊 Services status:"
	docker-compose -f $(COMPOSE_FILE) ps
