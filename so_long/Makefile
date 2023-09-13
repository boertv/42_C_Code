# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/31 14:06:40 by bvercaem          #+#    #+#              #
#    Updated: 2023/09/13 18:42:49 by bvercaem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long

BONUS_NAME		=

#-------------------PATH-----------------------------

SOURCES_WD		=	./

BONUS_WD		=

HEADER_WD		=	./

BONUS_HEADER_WD	=

#-------------------COMPILATION----------------------

CC				=	cc
#FLAGS			=	-Wall -Wextra -Werror
#FLAGS			=	-Wall -Wextra -Werror -g
FLAGS			=	-Wall -Wextra -Werror -fsanitize=address
OPENGL_APPKIT	=	-framework OpenGL -framework AppKit
LIBS			=	libft/libft.a -lmlx

#-------------------SOURCES FILES----------------------

HEADERS			=	$(HEADER_WD)so_long.h \
					$(HEADER_WD)sl_textures.h \
					mlx/mlx.h \
					libft/legacy/libft.h \
					libft/get_next_line/get_next_line.h \
					libft/ft_printf/ft_printf.h

BONUS_HEADERS 	=

MAIN			=	$(SOURCES_WD)so_long.c

BONUS_MAIN		=	$(BONUS_WD)main_bonus.c

SRCS			=	$(SOURCES_WD)sl_error.c \
					$(SOURCES_WD)sl_map_gen.c \
					$(SOURCES_WD)sl_map_checks.c \
					$(SOURCES_WD)sl_map_solvable.c \
					$(SOURCES_WD)sl_list_util.c \
					$(SOURCES_WD)sl_load_sprites.c \
					$(SOURCES_WD)sl_mlx_init.c \
					$(SOURCES_WD)sl_map.c \
					$(SOURCES_WD)sl_window_print.c \
					$(SOURCES_WD)sl_print_tile.c \
					$(SOURCES_WD)sl_print_shapes.c \
					$(SOURCES_WD)sl_print_util.c \
					$(SOURCES_WD)sl_print_clbl.c \
					$(SOURCES_WD)sl_mlx_loop.c \
					$(SOURCES_WD)sl_movement.c \
					$(SOURCES_WD)sl_map_updates.c \
					$(SOURCES_WD)sl_flush.c \

BONUS_SRC		=	$(BONUS_WD)___ _bonus.c

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

bonus:	$(BONUS_NAME)

%.o: %.c
	@printf "$(YELLOW)Generating $(NAME) objects... %-45.45s\r$(NO_COLOR)" $@
	@$(CC) $(FLAGS) $(I_HEADER) $(I_BONUS_HEADER) -c $< -o $@

$(NAME):	$(OBJS) $(MAIN_OBJ)
	@make -C libft/
	@make -C mlx/
	@printf "$(GREEN)Linking $(NAME)... %45s\r$(NO_COLOR)" " "
	@$(CC) $(FLAGS) $(OBJS) $(MAIN_OBJ) $(LIBS) $(OPENGL_APPKIT) -o $(NAME)
	@echo "\n$(GREEN)$(BOLD)Enjoy!$(BOLD_OFF)$(NO_COLOR)"

$(BONUS_NAME): $(OBJS) $(BONUS_OBJ) $(BONUS_MAIN_OBJ)
	@make -C libft/
	@make -C mlx/
	@printf "$(GREEN)Linking $(BONUS_NAME)... %45s\r$(NO_COLOR)" " "
	@$(CC) $(FLAGS) $(OBJS) $(BONUS_OBJ) $(BONUS_MAIN_OBJ) $(LIBS) $(OPENGL_APPKIT) -o $(BONUS_NAME)
	@echo "\n$(GREEN)$(BOLD)Enjoy!$(BOLD_OFF)$(NO_COLOR)"

clean:
	@echo "$(RED)Deleting objects...$(NO_COLOR)"
	@make clean -C libft/
	@make clean -C mlx/
	@rm -rf $(OBJS) $(BONUS_OBJ) $(MAIN_OBJ) $(BONUS_MAIN_OBJ)

fclean:	clean
	@make eclean -C libft/
	@echo "$(RED)Deleting executable...$(NO_COLOR)"
	@rm -f $(NAME) $(BONUS_NAME)

re: fclean all

rebonus : fclean bonus

nameclean:
	@echo "$(RED)Deleting $(NAME) objects...$(NO_COLOR)"
	@rm -rf $(OBJS) $(BONUS_OBJ) $(MAIN_OBJ) $(BONUS_MAIN_OBJ)

.PHONY: all clean fclean bonus re rebonus nameclean
