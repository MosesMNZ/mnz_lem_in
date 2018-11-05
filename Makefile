# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmuamba <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/18 07:52:00 by mmuamba           #+#    #+#              #
#    Updated: 2018/09/18 08:34:19 by mmuamba          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= lem_in

RCS			= ./resources

SRCS		= ./srcs/*.c

LIBFT		= ./libft

INCLUDES	= ./includes

FLAGS = -Wextra -Werror -Wall  -I./includes

CC = gcc

all: $(NAME)
$(NAME):
	@$(MAKE) -C $(LIBFT) all
	@$(CC) -o $(NAME) $(FLAGS) $(SRCS) libft/libft.a
	@echo "\x1B[32mLem_in compiled successfully\x1B[3m"

clean:
	@make clean -C libft
fclean:
	@make fclean -C libft
	@rm -f $(NAME)

re:	fclean all
