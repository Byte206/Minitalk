# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gamorcil <gamorcil@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/02 20:11:02 by gamorcil          #+#    #+#              #
#    Updated: 2025/10/02 20:11:08 by gamorcil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ================================= COLORS ==================================== #

RED			= \033[0;31m
GREEN		= \033[0;32m
YELLOW		= \033[0;33m
BLUE		= \033[0;34m
MAGENTA		= \033[0;35m
CYAN		= \033[0;36m
WHITE		= \033[0;37m
RESET		= \033[0m

# ================================= NOMBRES =================================== #

NAME		= server
CLIENT		= client

# ================================= ARCHIVOS ================================== #

SRC_SERVER	= server.c server_utils.c
SRC_CLIENT	= client.c client_utils.c

OBJ_SERVER	= $(SRC_SERVER:.c=.o)
OBJ_CLIENT	= $(SRC_CLIENT:.c=.o)

# ================================ DIRECTORIOS ================================ #

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

FT_PRINTF_DIR	= ft_printf
FT_PRINTF	= $(FT_PRINTF_DIR)/libftprintf.a

# ================================ COMPILACIÓN ================================ #

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= -I. -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR)
LIBS		= -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf

# ================================== REGLAS =================================== #

all: $(LIBFT) $(FT_PRINTF) $(NAME) $(CLIENT)

$(NAME): $(OBJ_SERVER)
	@echo "$(CYAN)🔨 Compilando $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ_SERVER) $(LIBS) -o $(NAME)
	@echo "$(GREEN)✅ $(NAME) compilado con éxito!$(RESET)"

$(CLIENT): $(OBJ_CLIENT)
	@echo "$(CYAN)🔨 Compilando $(CLIENT)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ_CLIENT) $(LIBS) -o $(CLIENT)
	@echo "$(GREEN)✅ $(CLIENT) compilado con éxito!$(RESET)"

%.o: %.c
	@echo "$(YELLOW)📝 Compilando $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@echo "$(MAGENTA)📚 Compilando libft...$(RESET)"
	@make -C $(LIBFT_DIR) --no-print-directory
	@echo "$(GREEN)✅ libft compilado!$(RESET)"

$(FT_PRINTF):
	@echo "$(MAGENTA)📚 Compilando ft_printf...$(RESET)"
	@make -C $(FT_PRINTF_DIR) --no-print-directory
	@echo "$(GREEN)✅ ft_printf compilado!$(RESET)"

clean:
	@echo "$(RED)🧹 Limpiando archivos objeto...$(RESET)"
	@rm -f $(OBJ_SERVER) $(OBJ_CLIENT)
	@make -C $(LIBFT_DIR) clean --no-print-directory
	@make -C $(FT_PRINTF_DIR) clean --no-print-directory
	@echo "$(GREEN)✅ Limpieza completada!$(RESET)"

fclean: clean
	@echo "$(RED)🗑️  Eliminando ejecutables...$(RESET)"
	@rm -f $(NAME) $(CLIENT)
	@make -C $(LIBFT_DIR) fclean --no-print-directory
	@make -C $(FT_PRINTF_DIR) fclean --no-print-directory
	@echo "$(GREEN)✅ Limpieza total completada!$(RESET)"

re: fclean all

bonus: all $(CLIENT)

# ================================== TESTING ================================== #

test: all
	@echo "$(CYAN)🧪 Iniciando servidor de prueba...$(RESET)"
	@./$(NAME)

run: all
	@echo "$(CYAN)🚀 Ejecutando servidor...$(RESET)"
	@./$(NAME)

# ================================= PHONY ===================================== #

.PHONY: all clean fclean re bonus test run
