# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/24 17:24:39 by bvercaem          #+#    #+#              #
#    Updated: 2023/08/18 12:52:58 by bvercaem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= get_next_line.tmp

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

HEADERS			=	$(HEADER_WD)get_next_line.h

SRCS			=	$(SOURCES)get_next_line.c \
					$(SOURCES)get_next_line_utils.c \

#-------------------OBJECTS----------------------

OBJS			=	$(SRCS:.c=.o)

#-------------------HEADERS----------------------

I_HEADER		=	$(addprefix( -include, $(HEADERS)))

#-------------------COLORS-----------------------

UNAME_S			=	$(shell uname -s)

ifeq ($(UNAME_S),Linux)	# colors for linux
RED				=	\033[0;31m
YELLOW			=	\033[1;33m
GREEN			=	\033[0;32m
NO_COLOR		=	\033[0m
BOLD			=	\033[1m
BOLD_OFF		=	\033[0m

else					# colors for mac
RED				=	\x1b[31m
YELLOW			=	\x1b[33m
GREEN			=	\x1b[32m
NO_COLOR		=	\x1b[0m
BOLD			= 	\x1b[1m
BOLD_OFF		=	\x1b[21m

endif

#-------------------RULES-----------------------

all:	$(NAME)

%.o: %.c
	@printf "$(YELLOW)Generating $(NAME) objects... %-45.45s\r$(NO_COLOR)" $@
	@$(CC) $(FLAGS) $(I_HEADER) -c $< -o $@

$(NAME):	$(OBJS)
	@printf "$(GREEN)Linking $(NAME)... %45c\n$(NO_COLOR)" ' '
	@ar -rcs $(STATIC_NAME) $(OBJS)
	@touch $(NAME)

clean:
	@echo "$(RED)Deleting $(NAME) objects...$(NO_COLOR)"
	@rm -rf $(OBJS) $(NAME)

fclean:	clean
	@echo "$(RED)Deleting executables...$(NO_COLOR)"
	@rm -f $(STATIC_NAME)

re: fclean all

.PHONY: all clean fclean re $(STATIC_NAME)
