# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/10 14:06:55 by bvercaem          #+#    #+#              #
#    Updated: 2023/04/17 10:41:36 by bvercaem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_isalnum.c \
	   ft_isprint.c \
	   ft_memcpy.c \
	   ft_putendl_fd.c \
	   ft_strchr.c \
	   ft_strlcat.c \
	   ft_strncmp.c \
	   ft_substr.c \
	   ft_atoi.c \
	   ft_isalpha.c \
	   ft_itoa.c \
	   ft_memmove.c \
	   ft_putnbr_fd.c \
	   ft_strdup.c \
	   ft_strlcpy.c \
	   ft_strnstr.c \
	   ft_tolower.c \
	   ft_bzero.c \
	   ft_isascii.c \
	   ft_memchr.c \
	   ft_memset.c \
	   ft_putstr_fd.c \
	   ft_striteri.c \
	   ft_strlen.c \
	   ft_strrchr.c \
	   ft_toupper.c \
	   ft_calloc.c \
	   ft_isdigit.c \
	   ft_memcmp.c \
	   ft_putchar_fd.c \
	   ft_split.c \
	   ft_strjoin.c \
	   ft_strmapi.c \
	   ft_strtrim.c

SRCS_B = ft_lstnew.c \
		 ft_lstadd_front.c \
		 ft_lstsize.c \
		 ft_lstlast.c \
		 ft_lstadd_back.c \
		 ft_lstdelone.c \
		 ft_lstclear.c \
		 ft_lstiter.c \
		 ft_lstmap.c

OBJS = $(SRCS:c=o)

OBJS_B = $(SRCS_B:c=o)

INCLUDE = libft.h

all: $(NAME)

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

$(NAME): $(OBJS) $(INCLUDE)
	@echo "creating libft library.."
	@ar -rcs $(NAME) $(OBJS)

bonus: $(OBJS) $(OBJS_B) $(INCLUDE)
	@echo "creating libft bonus library.."
	@ar -rcs $(NAME) $(OBJS) $(OBJS_B)

%.o: %.c Makefile
	${CC} ${CFLAGS} -c $< -I $(INCLUDE)

clean:
	@echo "cleaning libft folder.."
	@$(RM) $(OBJS)
	@$(RM) $(OBJS_B)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all re bonus
