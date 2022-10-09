# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arupert <arupert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/23 18:38:49 by arupert           #+#    #+#              #
#    Updated: 2022/07/09 22:35:56 by arupert          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FILES	= count_rotation_utils.c \
			  count_scores.c \
			  check_errors.c \
			  error.c \
			  fill_the_rank.c \
			  final_sort.c \
			  ft_atoi.c \
			  ft_split.c \
			  libft.c \
			  lists.c \
			  operations1.c \
			  operations2.c \
			  parser.c \
			  preparations.c \
			  push1.c \
			  push2.c \
			  main.c

BSRC_FILES	= checker.c \
			  error.c \
			  check_errors.c \
			  ft_atoi.c \
			  ft_split.c \
			  libft_checker.c \
			  libft.c \
			  lists.c \
			  operations1.c \
			  operations2.c \
			  parser.c \

OBJS		= $(SRC_FILES:.c=.o)
BOBJS		= $(BSRC_FILES:.c=.o)

HEADER		= push_swap.h

NAME		= push_swap
BNAME		= checker

CC			= cc

CFLAGS		= -Wall -Werror -Wextra

RM			= rm -f

.PHONY:		all clean fclean re bonus

%.o:		%.c $(HEADER) Makefile
			$(CC) -c $(CFLAGS) $< -o $@

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus:		$(BNAME)

$(BNAME):	$(BOBJS)
			$(CC) $(CFLAGS) $(BOBJS) -o $(BNAME)

all:		$(NAME)

clean:
	$(RM) $(OBJS)
	${RM} $(BOBJS)

fclean:		clean
	$(RM) $(NAME)
	$(RM) $(BNAME)
	
re:			fclean all
