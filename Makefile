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
SERVER_NAME		= server
CLIENT_NAME		= client

# Compilador y flags
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -I. -Ift_printf

# ft_printf
FT_PRINTF_DIR	= ft_printf
FT_PRINTF_A		= $(FT_PRINTF_DIR)/libftprintf.a

# Archivos fuente
COMMON_SRCS		= ft_atoi.c ft_strlen.c
SERVER_SRCS		= server.c $(COMMON_SRCS)
CLIENT_SRCS		= client.c $(COMMON_SRCS)

SERVER_OBJS		= $(SERVER_SRCS:.c=.o)
CLIENT_OBJS		= $(CLIENT_SRCS:.c=.o)

# Reglas principales
all: $(FT_PRINTF_A) $(SERVER_NAME) $(CLIENT_NAME)

$(FT_PRINTF_A):
	make -C $(FT_PRINTF_DIR)

$(SERVER_NAME): $(SERVER_OBJS)
	$(CC) $(CFLAGS) $(SERVER_OBJS) $(FT_PRINTF_A) -o $(SERVER_NAME)

$(CLIENT_NAME): $(CLIENT_OBJS)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) $(FT_PRINTF_A) -o $(CLIENT_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(FT_PRINTF_DIR)
	rm -f $(SERVER_OBJS) $(CLIENT_OBJS)

fclean: clean
	make fclean -C $(FT_PRINTF_DIR)
	rm -f $(SERVER_NAME) $(CLIENT_NAME)

re: fclean all

.PHONY: all clean fclean re
