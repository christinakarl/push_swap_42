# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/06 15:04:04 by ckarl             #+#    #+#              #
#    Updated: 2023/06/16 11:54:58 by ckarl            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= main.c error_management.c list_management.c bubble_sort.c \
				  operations_1.c operations_2.c operations_3.c algorithms.c \
				  b_manipulations.c helpers_1.c helpers_2.c order.c \
				  node_manipulations.c

OBJS			= ${SRCS:.c=.o}

HEADER  		= push_swap.h

LIBS			= -Llibft -lft

OTH_HEAD		= -Ilibft

NAME			= push_swap

CC				= gcc

CFLAGS			= -Wall -Wextra -Werror -g

RM				= rm -f

COLOUR_GREEN	=\033[1;32m
COLOUR_RED		=\033[0;31m
COLOUR_YELL		=\033[0;33m
COLOUR_TURQ		=\033[1;36m
COLOUR_WHITE	=\033[1;37m
COLOUR_BLUE		=\033[1;34m
COLOUR_VIO		=\033[1;35m
COLOUR_END		=\033[0m

%.o: %.c
				${CC} -c ${CFLAGS} $< -o $@

all:			${NAME}

${NAME}:		${OBJS}
				cd libft; make bonus
				${CC} ${CFLAGS} -o $@ ${OBJS} ${LIBS} ${OTH_HEAD}
				@echo "$(COLOUR_GREEN)( ಠ ͜ʖ ಠ )$(COLOUR_END)"

clean:
				${RM} ${OBJS}
				cd libft; make clean

fclean:			clean
				${RM} ${NAME}
				cd libft; make fclean
				@echo "$(COLOUR_VIO)All clean!$(COLOUR_END)"

re:				fclean all

.PHONY:			all clean fclean re

