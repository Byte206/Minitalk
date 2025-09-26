# **************************************************************************** #
#                                   VARIABLES                                  #
# **************************************************************************** #

NAME_SERVER    = server_bonus
NAME_CLIENT    = client_bonus

SRCS_SERVER    = server_bonus.c
SRCS_CLIENT    = client_bonus.c

OBJS_SERVER    = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT    = $(SRCS_CLIENT:.c=.o)

CC             = gcc
CFLAGS         = -Wall -Wextra -Werror -I. -I../libft -I../ft_printf -I..

LIBFT          = ../libft/libft.a
FT_PRINTF      = ../ft_printf/libftprintf.a

# **************************************************************************** #
#                                    RULES                                     #
# **************************************************************************** #

all: $(NAME_SERVER) $(NAME_CLIENT)

$(LIBFT):
	$(MAKE) -C ../libft

$(FT_PRINTF):
	$(MAKE) -C ../ft_printf

$(NAME_SERVER): $(OBJS_SERVER) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJS_SERVER) $(LIBFT) $(FT_PRINTF) -o $(NAME_SERVER)

$(NAME_CLIENT): $(OBJS_CLIENT) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) $(LIBFT) $(FT_PRINTF) -o $(NAME_CLIENT)

clean:
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT)
	$(MAKE) -C ../libft clean
	$(MAKE) -C ../ft_printf clean

fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)
	$(MAKE) -C ../libft fclean
	$(MAKE) -C ../ft_printf fclean

re: fclean all

.PHONY: all clean fclean re

