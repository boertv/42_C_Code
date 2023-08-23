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
OPENGL_APPKIT	=	-framework OpenGL -framework AppKit
LIBS			=	libft/libft.a -lmlx

#-------------------SOURCES FILES----------------------

HEADERS			=	$(HEADER_WD)so_long.h \
					mlx/mlx.h \
					libft/legacy/libft.h

BONUS_HEADERS 	=

MAIN			=	$(SOURCES_WD)test.c

BONUS_MAIN		=	$(BONUS_WD)main_bonus.c

SRCS			=

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

.PHONY: all clean fclean bonus re rebonus
