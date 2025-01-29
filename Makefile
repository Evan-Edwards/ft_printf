# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/20 15:23:06 by eedwards          #+#    #+#              #
#    Updated: 2025/01/29 11:54:54 by eedwards         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc -g -I./incl
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

SRCS = src/ft_printf.c src/ft_putchar.c src/ft_putnbr_p.c src/ft_putnbr.c \
	src/ft_putstr.c

OBJS = $(SRCS:.c=.o)

obj/%.o: src/%.c
	@mkdir -p obj
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(NAME) created"

clean:
	@$(RM) -r obj
	@echo "Object files removed"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(NAME) removed"

re: fclean $(NAME)

.PHONY: all clean fclean re
