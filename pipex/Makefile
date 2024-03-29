# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/05 15:41:13 by bvercaem          #+#    #+#              #
#    Updated: 2023/08/18 13:11:45 by bvercaem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	pipex

BONUS_NAME		=

#-------------------PATH-----------------------------

SOURCES_WD		=	./

BONUS_WD		=	./

HEADER_WD		=	./

BONUS_HEADER_WD	=	./

#-------------------COMPILATION----------------------

CC				=	cc
FLAGS			=	-Wall -Wextra -Werror
#FLAGS			=	-Wall -Wextra -Werror -g
#FLAGS			=	-Wall -Wextra -Werror -fsanitize=address

MAKE			=	make --no-print-directory

#-------------------SOURCES FILES----------------------

HEADERS			=	$(HEADER_WD)pipex.h \
					$(HEADER_WD)libft/legacy/libft.h

BONUS_HEADERS 	=	$(BONUS_HEADER_WD)pipex_bonus.h \
					$(BONUS_HEADER_WD)libft/get_next_line/get_next_line.h

MAIN			=	$(SOURCES_WD)pipex.c

BONUS_MAIN		=	$(BONUS_WD)pipex_bonus.c

SRCS			=	$(SOURCES_WD)px_first_last_step.c \
					$(SOURCES_WD)px_pipes.c \
					$(SOURCES_WD)px_execution.c \
					$(SOURCES_WD)px_execution_utils.c \
					$(SOURCES_WD)px_end.c

BONUS_SRC		=	$(BONUS_WD)px_heredoc_bonus.c

#-------------------OBJECTS----------------------

OBJS			=	$(SRCS:.c=.o)

BONUS_OBJ		=	$(BONUS_SRC:.c=.o)

MAIN_OBJ		=	$(MAIN:.c=.o)

BONUS_MAIN_OBJ	=	$(BONUS_MAIN:.c=.o)

#-------------------HEADERS----------------------

I_HEADER		=	$(addprefix( -include, $(HEADERS)))

I_BONUS_HEADER	=	$(addprefix( -include, $(BONUS_HEADERS)))

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
	@$(CC) $(FLAGS) $(I_HEADER) $(I_BONUS_HEADER) -c $< -o $@

$(NAME):	$(OBJS) $(MAIN_OBJ)
	@$(MAKE) -C libft/
	@printf "$(GREEN)Linking $(NAME)... %45s\r$(NO_COLOR)" " "
	@$(CC) $(FLAGS) $(OBJS) $(MAIN_OBJ) libft/libft.a -o $(NAME)
	@echo "\n$(GREEN)$(BOLD)Enjoy!$(BOLD_OFF)$(NO_COLOR)"

bonus:	$(OBJS) $(BONUS_OBJ) $(BONUS_MAIN_OBJ)
	@rm -rf $(NAME)
	@$(MAKE) -C libft/
	@printf "$(GREEN)Linking $(NAME)... %45s\r$(NO_COLOR)" " "
	@$(CC) $(FLAGS) $(OBJS) $(BONUS_OBJ) $(BONUS_MAIN_OBJ) libft/libft.a -o $(NAME)
	@echo "\n$(GREEN)$(BOLD)Enjoy!$(BOLD_OFF)$(NO_COLOR)"

clean:
	@echo "$(RED)Deleting objects...$(NO_COLOR)"
	@$(MAKE) clean -C libft/
	@rm -rf $(OBJS) $(BONUS_OBJ) $(MAIN_OBJ) $(BONUS_MAIN_OBJ)

fclean:	clean
	@echo "$(RED)Deleting executables...$(NO_COLOR)"
	@$(MAKE) fclean -C libft/
	@rm -f $(NAME) $(BONUS_NAME)

re: fclean all

rebonus : fclean bonus

eclean:
	@rm -rf $(NAME)

remake: eclean all

.PHONY: all clean fclean bonus re rebonus eclean remake
