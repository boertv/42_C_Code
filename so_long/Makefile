NAME			=	so_long

BONUS_NAME		=

#-------------------PATH-----------------------------

SOURCES_WD		=	./

BONUS_WD		=

HEADER_WD		=	./

BONUS_HEADER_WD	=

#-------------------COMPILATION----------------------

CC				=	cc
FLAGS			=	-Wall -Wextra -Werror
# FLAGS			=	-Wall -Wextra -Werror -g
# FLAGS			=	-Wall -Wextra -Werror -fsanitize=address
MLX_FLAG		=	-Imlx

#-------------------SOURCES FILES----------------------

HEADERS			=	$(HEADER_WD)so_long.h

BONUS_HEADERS 	=

H_LIB 			= 	$(___ _WD)___.h \
					$(___ _WD)___.h

MAIN			=	$(SOURCES_WD)main.c

BONUS_MAIN		=	$(BONUS_WD)main_bonus.c

SRCS			=	$(SOURCES_WD)___.c \
					$(SOURCES_WD)___.c \
					$(SOURCES_WD)___.c \

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

RED				=	\x1b[31m

YELLOW			=	\x1b[33m

GREEN			=	\x1b[32m

NO_COLOR		=	\x1b[0m

BOLD			= 	\x1b[1m

BOLD_OFF		=	\x1b[21m


#-------------------RULES-----------------------

all:	$(NAME)

bonus:	$(BONUS_NAME)

%.o: %.c
	@printf "$(YELLOW)Generating $(NAME) objects... %-45.45s\r$(NO_COLOR)" $@
	@$(CC) $(FLAGS) $(MLX_FLAG) $(I_HEADER) $(I_BONUS_HEADER) -c $< -o $@

$(NAME):	$(OBJS) $(MAIN_OBJ)
	@make -C libft/
	@make -C mlx/
	@printf "$(GREEN)Linking $(NAME)... %45s\r$(NO_COLOR)" " "
	@$(CC) $(FLAGS) $(OBJS) $(MAIN_OBJ) libft/libft.a -o $(NAME)
	@echo "\n$(GREEN)$(BOLD)Enjoy!$(BOLD_OFF)$(NO_COLOR)"

$(BONUS_NAME): $(OBJS) $(BONUS_OBJ) $(BONUS_MAIN_OBJ)
	@make -C libft/
	@make -C mlx/
	@printf "$(GREEN)Linking $(BONUS_NAME)... %45s\r$(NO_COLOR)" " "
	@$(CC) $(FLAGS) $(OBJS) $(BONUS_OBJ) $(BONUS_MAIN_OBJ) libft/libft.a -o $(BONUS_NAME)
	@echo "\n$(GREEN)$(BOLD)Enjoy!$(BOLD_OFF)$(NO_COLOR)"

clean:
	@echo "$(RED)Deleting objects...$(NO_COLOR)"
	@make clean -C libft/
	@make clean -C mlx/
	@rm -rf $(OBJS) $(BONUS_OBJ) $(MAIN_OBJ) $(BONUS_MAIN_OBJ)

fclean:	clean
	@make eclean -C libft/
	@echo "$(RED)Deleting executables...$(NO_COLOR)"
	@rm -f $(NAME) $(BONUS_NAME)

re: fclean all

rebonus : fclean bonus

.PHONY: all clean fclean bonus re rebonus
