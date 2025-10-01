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

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)

# Carpetas de librerías
LIBFT_DIR = libft
PRINTF_DIR = ft_printf

LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF = $(PRINTF_DIR)/libftprintf.a

# Compilador y flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(LIBFT_DIR) -I$(PRINTF_DIR)

# Regla por defecto
all: $(CLIENT) $(SERVER)

# Cliente
$(CLIENT): $(OBJ_CLIENT) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) -o $@ $(OBJ_CLIENT) $(LIBFT) $(FT_PRINTF)

# Servidor
$(SERVER): $(OBJ_SERVER) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) -o $@ $(OBJ_SERVER) $(LIBFT) $(FT_PRINTF)

# Librerías
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

# Limpieza
clean:
	rm -f $(OBJ_CLIENT) $(OBJ_SERVER)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(CLIENT) $(SERVER)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

