NAME			=	philo

#-------------------PATH-----------------------------

SOURCES_WD		=	./

HEADER_WD		=	./

#-------------------COMPILATION----------------------

CC				=	cc
#FLAGS			=	-Wall -Wextra -Werror
FLAGS			=	-Wall -Wextra -Werror -g
#FLAGS			=	-Wall -Wextra -Werror -fsanitize=address

MAKE			=	make --no-print-directory

#-------------------SOURCES FILES----------------------

HEADERS			=	$(HEADER_WD)philo.h

MAIN			=	$(SOURCES_WD)philo.c

SRCS			=	$(SOURCES_WD)ph_atoi.c \
					$(SOURCES_WD)ph_assemble.c \
					$(SOURCES_WD)ph_behaviour.c \
					$(SOURCES_WD)ph_flush.c \
					$(SOURCES_WD)ph_reaper.c \
					$(SOURCES_WD)ph_msleep.c \

#-------------------OBJECTS----------------------

OBJS			=	$(SRCS:.c=.o)

MAIN_OBJ		=	$(MAIN:.c=.o)

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

$(NAME):	$(OBJS) $(MAIN_OBJ)
	@printf "$(GREEN)Linking $(NAME)... %45s\r$(NO_COLOR)" " "
	@$(CC) $(FLAGS) $(OBJS) $(MAIN_OBJ) -o $(NAME)
	@echo "\n$(GREEN)$(BOLD)Enjoy!$(BOLD_OFF)$(NO_COLOR)"

clean:
	@echo "$(RED)Deleting $(NAME) objects...$(NO_COLOR)"
	@rm -rf $(OBJS) $(MAIN_OBJ)

fclean:	clean
	@echo "$(RED)Deleting executable...$(NO_COLOR)"
	@rm -f $(NAME)
	@rm -rf $(NAME).dSYM

re: fclean all

.PHONY: all clean fclean re
