# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/21 15:35:55 by bvercaem          #+#    #+#              #
#    Updated: 2023/05/09 13:03:53 by bvercaem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = libft/libft.a

SRCS = ft_printf.c \
	   ft_conv_hub.c \
	   ft_conv_char.c \
	   ft_conv_str.c \
	   ft_conv_nb.c \
	   ft_fill_nb.c \
	   ft_check_flags.c \
	   ft_flags.c \
	   ft_flags_2.c \
	   ft_error.c

OBJS = $(SRCS:c=o)

INCLUDES = libft/libft.h \
		  ft_printf.h

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

all: $(NAME)

bonus: all

$(LIBFT):
	make bonus -C libft

$(NAME): $(LIBFT) $(OBJS) $(INCLUDES)
	@cp $(LIBFT) $(NAME)
	@echo "creating printf library.."
	@ar -rcs $(NAME) $(OBJS)

%.o: %.c Makefile
	${CC} ${CFLAGS} -c $< -I $(INCLUDES)

clean:
	make clean -C libft
	@echo "cleaning printf folder.."
	@$(RM) $(OBJS)

fclean: clean
	$(RM) $(LIBFT)
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all re bonus
