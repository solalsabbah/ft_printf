# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/29 10:48:28 by ssabbah           #+#    #+#              #
#    Updated: 2017/12/22 12:39:44 by ssabbah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libftprintf.a

SRC= src/*.c 

OBJ= $(addprefix $(OBJDIR), $(SRC:.c=o.))

CC = gcc

HEADER= includes
FLAGS=  -w -g -Wall -Wextra -Werror

SRCDIR= ./src/
INCDIR= ./includes/
OBJDIR= ./obj/

all: $(NAME)

obj:
	@ mkdir -p $(OBJDIR)

$(NAME): obj
	@ $(CC) $(FLAGS) -I $(HEADER) -c $(SRC)
	@ mv  *.o $(OBJDIR)
	@ ar rc $(NAME) obj/*.o
	@echo  '\x1b[42m' '\x1b[34m' " *================================*  " '\x1b[0m'
	@echo  '\x1b[42m' '\x1b[34m' " *                                *  " '\x1b[0m'
	@echo  '\x1b[42m' '\x1b[34m' " *  Compiling libftprintf.a... OK *  " '\x1b[0m'
	@echo  '\x1b[42m' '\x1b[34m' " *                                *  " '\x1b[0m'
	@echo  '\x1b[42m' '\x1b[34m' " *================================*  " '\x1b[0m'

clean:
	@ rm -rf obj/*.o

fclean: clean
	@ rm -f $(NAME)
	@ rm -rf $(OBJDIR)

re: fclean all
