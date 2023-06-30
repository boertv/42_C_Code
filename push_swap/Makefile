# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/05 17:48:56 by bvercaem          #+#    #+#              #
#    Updated: 2023/06/30 15:15:23 by bvercaem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap

BONUS_NAME		= checker

#-------------------PATH-----------------------------

SOURCES_WD		= ./

BONUS_WD		= ./

HEADER_WD		= ./

BONUS_HEADER_WD	= ./

#-------------------COMPILATION----------------------

CC				=	cc
FLAGS			=	-Wall -Werror -Wextra
# FLAGS			=	-Wall -Werror -Wextra -fsanitize=address

#-------------------SOURCES FILES----------------------

HEADERS			=	$(HEADER_WD)push_swap.h \
					$(HEADER_WD)libft/legacy/libft.h \
					$(HEADER_WD)libft/ft_printf/ft_printf.h

BONUS_HEADERS 	=	$(BONUS_HEADER_WD)push_swap_bonus.h \
					$(BONUS_HEADER_WD)libft/get_next_line/get_next_line.h

MAIN			=	$(SOURCES_WD)ps_main.c

BONUS_MAIN		=	$(BONUS_WD)ps_main_bonus.c

SRCS			=	$(SOURCES_WD)ps_initialise_stack.c \
					$(SOURCES_WD)ps_error.c \
					$(SOURCES_WD)ps_checks.c \
					$(SOURCES_WD)ps_operations.c \
					$(SOURCES_WD)ps_double_operations.c \
					$(SOURCES_WD)ps_list_new_add_del.c \
					$(SOURCES_WD)ps_chunk_utils.c \
					$(SOURCES_WD)ps_small_sorts.c \
					$(SOURCES_WD)ps_big_sort.c \
					$(SOURCES_WD)ps_big_sort_utils.c \
					$(SOURCES_WD)ps_stack_manoeuvres.c \
					$(SOURCES_WD)ps_attributes.c \
					$(SOURCES_WD)ps_print_utils.c \
					$(SOURCES_WD)ps_print_print.c \
					$(SOURCES_WD)ps_print_trim.c \
					$(SOURCES_WD)ps_print_optimisation.c \
					$(SOURCES_WD)ps_initialise_utils.c

BONUS_SRC		=	$(BONUS_WD)ps_parser_bonus.c

#-------------------OBJECTS----------------------

OBJS			=	$(SRCS:.c=.o)

BONUS_OBJ		=	$(BONUS_SRC:.c=.o)

MAIN_OBJ		=	$(MAIN:.c=.o)

BONUS_MAIN_OBJ	=	$(BONUS_MAIN:.c=.o)

#-------------------HEADERS----------------------

I_HEADER		=	$(addprefix( -include, $(HEADERS)))

I_BONUS_HEADER	=	$(addprefix( -include, $(BONUS_HEADERS)))

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
	@$(CC) $(FLAGS) $(I_HEADER) $(I_BONUS_HEADER) -c $< -o $@

$(NAME):	$(OBJS) $(MAIN_OBJ)
	@make -C libft/
	@printf "$(GREEN)Linking $(NAME)... %45s\r$(NO_COLOR)" " "
	@$(CC) $(FLAGS) $(OBJS) $(MAIN_OBJ) libft/libft.a -o $(NAME)
	@echo "\n$(GREEN)$(BOLD)Enjoy!$(BOLD_OFF)$(NO_COLOR)"

bonus: $(OBJS) $(BONUS_OBJ) $(BONUS_MAIN_OBJ)
	@make -C libft/
	@printf "$(GREEN)Linking $(BONUS_NAME)... %45s\r$(NO_COLOR)" " "
	@$(CC) $(FLAGS) $(OBJS) $(BONUS_OBJ) $(BONUS_MAIN_OBJ) libft/libft.a -o $(BONUS_NAME)
	@echo "\n$(GREEN)$(BOLD)Enjoy!$(BOLD_OFF)$(NO_COLOR)"

clean:
	@echo "$(RED)Deleting objects...$(NO_COLOR)"
	@make clean -C libft/
	@rm -rf $(OBJS) $(BONUS_OBJ) $(MAIN_OBJ)

fclean:
	@echo "$(RED)Deleting objects...$(NO_COLOR)"
	@rm -rf $(OBJS) $(BONUS_OBJ) $(MAIN_OBJ)
	@echo "$(RED)Deleting executables...$(NO_COLOR)"
	@make fclean -C libft/
	@rm -f $(NAME) $(BONUS_NAME)

re: fclean all

rebonus : fclean bonus

.PHONY: all clean fclean bonus re rebonus
