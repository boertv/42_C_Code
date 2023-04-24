# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/21 15:35:55 by bvercaem          #+#    #+#              #
#    Updated: 2023/04/24 17:24:59 by bvercaem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = $(wildcard *.c) \
	   $(wildcard libft/*.c)

OBJS = $(SRCS:c=o)

INCLUDES = libft/libft.h \
		  ft_printf.h

all: $(NAME)

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

$(NAME): $(OBJS) $(INCLUDES)
	ar -rcs $(NAME) $(OBJS)

%.o: %.c Makefile
	${CC} ${CFLAGS} -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all re
