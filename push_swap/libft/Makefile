# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckarl <marvin@42lausanne.ch>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/25 13:33:18 by ckarl             #+#    #+#              #
#    Updated: 2023/04/18 19:50:03 by ckarl            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
			ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
			ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_split.c ft_strchr.c \
			ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c\
			ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c \
			ft_toupper.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
			ft_putnbr_fd.c ft_printf.c ft_printbasics.c ft_printptr.c ft_printhex.c ft_itoa_u.c \
			ft_printnbr.c

BONUS_SRCS	= ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

BONUS_OBJS	= ${BONUS_SRCS:.c=.o}

OBJS		= ${SRCS:.c=.o}

HEADER		= libft.h

NAME		= libft.a

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror -I${HEADER}

RM			= rm -f

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}
			ar rcs ${NAME} ${OBJS}

bonus:		${OBJS} ${BONUS_OBJS}
			ar rcs ${NAME} ${OBJS} ${BONUS_OBJS}

clean:
			${RM} ${OBJS} ${BONUS_OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re bonus
