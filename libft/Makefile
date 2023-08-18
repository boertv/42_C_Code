# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/23 15:19:16 by bvercaem          #+#    #+#              #
#    Updated: 2023/08/18 12:51:40 by bvercaem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libft.a

#-------------------SOURCES FILES----------------------
# functions need to link their object files into ../libft.a

STATIC_NAMES		=	legacy \
						ft_printf \
						get_next_line \

STATIC_WD			=	$(STATIC_NAMES:%=%/)

STATIC_LIBS			=	$(STATIC_NAMES:%=%.a)

STATIC_WDLIBS		=	$(join $(STATIC_WD),$(STATIC_LIBS))

CLEAN_LIBS			=	$(addsuffix .clean,$(STATIC_WD))

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

$(NAME): $(STATIC_WD)
	@echo "$(GREEN)$(BOLD)Finished libft!\n$(BOLD_OFF)$(NO_COLOR)"

$(STATIC_WD):
	@make -C $@

$(CLEAN_LIBS): %.clean:
	@make clean -C $*

clean: $(CLEAN_LIBS)

eclean:
	@echo "$(RED)Deleting $(NAME)...$(NO_COLOR)"
	@rm -f $(NAME)

fclean:	clean eclean
	@echo "$(RED)$(BOLD)All clean!\n$(BOLD_OFF)$(NO_COLOR)"

re: fclean all

.PHONY: all clean fclean eclean re $(STATIC_WD) $(CLEAN_LIBS)
