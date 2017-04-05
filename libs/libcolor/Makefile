# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/31 05:33:26 by ahamouda          #+#    #+#              #
#    Updated: 2016/03/31 05:33:36 by ahamouda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=		libcolor.a

COMPILER=	gcc
FLAGS=		-Werror -Wextra -Wall
INCLUDES=	-I./includes

SRC_C=\
			color_new.c\
			color_del.c\
			color_get.c\
			color_convert.c\
			color_average.c\
			color_step.c

SRC_O=$(SRC_C:.c=.o)

.PHONY:	all clean fclean re norm

all: objects $(SRC_O:%=objects/%) $(NAME)

objects:
	@mkdir objects

objects/%.o: srcs/%.c
	@echo "Compling $< ..."
	@$(COMPILER) $(FLAGS) $(INCLUDES) -c $<
	@mv $(notdir $@) objects

$(NAME): $(SRC_C:%=srcs/%)
	@ar -rc $(NAME) $(SRC_O:%=objects/%)
	@echo "Libcolor has been created!"

clean:
	rm -rf objects

fclean: clean
	rm -rf libcolor.a

re: fclean all

norm:
	norminette srcs includes
