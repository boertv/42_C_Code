# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/23 15:19:16 by bvercaem          #+#    #+#              #
#    Updated: 2023/05/25 16:04:47 by bvercaem         ###   ########.fr        #
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

RED				=	\x1b[31m

YELLOW			=	\x1b[33m

GREEN			=	\x1b[32m

NO_COLOR		=	\x1b[0m

BOLD			= 	\x1b[1m

BOLD_OFF		=	\x1b[21m

#-------------------RULES-----------------------

all:	$(NAME)

$(NAME): $(STATIC_WD)
	@echo "$(GREEN)$(BOLD)Enjoy!\n$(BOLD_OFF)$(NO_COLOR)"

$(STATIC_WD):
	make -C $@

$(CLEAN_LIBS): %.clean:
	make clean -C $*

clean: $(CLEAN_LIBS)

fclean:	clean
	@echo "$(RED)Deleting executable...\n$(NO_COLOR)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re $(STATIC_WD) $(CLEAN_LIBS)
