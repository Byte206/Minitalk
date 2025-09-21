# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gamorcil <gamorcil@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/01 14:39:13 by gamorcil          #+#    #+#              #
#    Updated: 2025/07/01 14:39:13 by gamorcil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Ejecutables
CLIENT = client
SERVER = server

# Fuentes principales
SRC_CLIENT = client.c
SRC_SERVER = server.c

# Carpetas de librerías
LIBFT_DIR = libft
PRINTF_DIR = ft_printf

# Archivos fuente de librerías
LIBFT_SRC = $(wildcard $(LIBFT_DIR)/*.c)
PRINTF_SRC = $(wildcard $(PRINTF_DIR)/*.c)

# Objetos
LIBFT_OBJ = $(LIBFT_SRC:.c=.o)
PRINTF_OBJ = $(PRINTF_SRC:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)

# Compilador y flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(LIBFT_DIR) -I$(PRINTF_DIR)

# Regla por defecto
all: $(CLIENT) $(SERVER)

# Cliente
$(CLIENT): $(OBJ_CLIENT) $(LIBFT_OBJ) $(PRINTF_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Servidor
$(SERVER): $(OBJ_SERVER) $(LIBFT_OBJ) $(PRINTF_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Compilación de objetos de libft y ft_printf
$(LIBFT_DIR)/%.o: $(LIBFT_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(PRINTF_DIR)/%.o: $(PRINTF_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpieza
clean:
	rm -f $(OBJ_CLIENT) $(OBJ_SERVER) $(LIBFT_OBJ) $(PRINTF_OBJ)

fclean: clean
	rm -f $(CLIENT) $(SERVER)

re: fclean all
