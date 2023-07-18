# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/10 14:06:55 by bvercaem          #+#    #+#              #
#    Updated: 2023/07/18 17:16:33 by bvercaem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= legacy.tmp

STATIC_NAME		= ../libft.a

#-------------------PATH-----------------------------

SOURCES			= ./

HEADER_WD		= ./

#-------------------COMPILATION----------------------

CC				=	cc
FLAGS			=	-Wall -Wextra -Werror
# FLAGS			=	-Wall -Wextra -Werror -g
# FLAGS			=	-Wall -Wextra -Werror -fsanitize=address

#-------------------SOURCES FILES----------------------

HEADERS			=	$(HEADER_WD)libft.h

SRCS			=	$(SOURCES)ft_isalpha.c \
					$(SOURCES)ft_isdigit.c \
					$(SOURCES)ft_isalnum.c \
					$(SOURCES)ft_isascii.c \
					$(SOURCES)ft_isprint.c \
					$(SOURCES)ft_strlen.c \
					$(SOURCES)ft_memset.c \
					$(SOURCES)ft_bzero.c \
					$(SOURCES)ft_memcpy.c \
					$(SOURCES)ft_memmove.c \
					$(SOURCES)ft_strlcpy.c \
					$(SOURCES)ft_strlcat.c \
					$(SOURCES)ft_toupper.c \
					$(SOURCES)ft_tolower.c \
					$(SOURCES)ft_strchr.c \
					$(SOURCES)ft_strrchr.c \
					$(SOURCES)ft_strncmp.c \
					$(SOURCES)ft_memchr.c \
					$(SOURCES)ft_memcmp.c \
					$(SOURCES)ft_strnstr.c \
					$(SOURCES)ft_atoi.c \
					$(SOURCES)ft_calloc.c \
					$(SOURCES)ft_strdup.c \
					$(SOURCES)ft_substr.c \
					$(SOURCES)ft_strjoin.c \
					$(SOURCES)ft_strtrim.c \
					$(SOURCES)ft_split.c \
					$(SOURCES)ft_itoa.c \
					$(SOURCES)ft_strmapi.c \
					$(SOURCES)ft_striteri.c \
					$(SOURCES)ft_putchar_fd.c \
					$(SOURCES)ft_putstr_fd.c \
					$(SOURCES)ft_putendl_fd.c \
					$(SOURCES)ft_putnbr_fd.c \
					$(SOURCES)ft_lstnew.c \
					$(SOURCES)ft_lstadd_front.c \
					$(SOURCES)ft_lstsize.c \
					$(SOURCES)ft_lstlast.c \
					$(SOURCES)ft_lstadd_back.c \
					$(SOURCES)ft_lstdelone.c \
					$(SOURCES)ft_lstclear.c \
					$(SOURCES)ft_lstiter.c \
					$(SOURCES)ft_lstmap.c \
					$(SOURCES)ft_strstr.c \
					$(SOURCES)ft_strshift.c

#-------------------OBJECTS----------------------

OBJS			=	$(SRCS:.c=.o)

#-------------------HEADERS----------------------

I_HEADER		=	$(addprefix( -include, $(HEADERS)))

#-------------------COLORS-----------------------

RED				=	\x1b[31m

YELLOW			=	\x1b[33m

GREEN			=	\x1b[32m

NO_COLOR		=	\x1b[0m

BOLD			= 	\x1b[1m

BOLD_OFF		=	\x1b[21m


#-------------------RULES-----------------------

all:	$(NAME)

%.o: %.c
	@printf "$(YELLOW)Generating $(NAME) objects... %-45.45s\r$(NO_COLOR)" $@
	@$(CC) $(FLAGS) $(I_HEADER) -c $< -o $@

$(NAME):	$(OBJS)
	@touch $(NAME)
	@printf "$(GREEN)Linking $(NAME)... %45c\n$(NO_COLOR)" ' '
	@ar -rcs $(STATIC_NAME) $(OBJS)

clean:
	@echo "$(RED)Deleting $(NAME) objects...$(NO_COLOR)"
	@rm -rf $(OBJS) $(NAME)

fclean:	clean
	@echo "$(RED)Deleting executables...$(NO_COLOR)"
	@rm -f $(STATIC_NAME)

re: fclean all

.PHONY: all clean fclean re $(STATIC_NAME)
