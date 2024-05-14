# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/24 11:47:10 by eedwards          #+#    #+#              #
#    Updated: 2024/04/24 11:47:20 by eedwards         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
	ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
	ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c \
	ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
	ft_strjoin.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
	ft_tolower.c ft_toupper.c
BSRCS = ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c \
	ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c \
	ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c
OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	$(CC) $(CFLAGS) -c $?

all: $(NAME)
bonus: .bonus

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

.bonus: $(OBJS) $(BOBJS)
	ar rcs $(NAME) $(OBJS) $(BOBJS)
	@touch .bonus

clean:
	$(RM) $(OBJS) $(BOBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re bonus