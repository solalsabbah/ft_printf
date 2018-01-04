# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/29 10:48:28 by ssabbah           #+#    #+#              #
#    Updated: 2018/01/04 11:51:29 by ssabbah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libftprintf.a

FILES= 	abs_val.c\
	casting.c\
	field.c\
	find_char.c\
	format.c\
	ft_atoi.c\
	ft_bzero.c\
	ft_convert.c\
	ft_getwchar.c\
	ft_isdigit.c\
	ft_printf.c\
	ft_putchar.c\
	ft_putnbr.c\
	ft_putnbr_uns.c\
	ft_putsign.c\
	ft_putstr.c\
	ft_strcat.c\
	ft_strdup.c\
	ft_strjoin.c\
	ft_strlen.c\
	ft_strncmp.c\
	ft_strnew.c\
	ft_strpbrk.c\
	ft_strrev.c\
	ft_strsub.c\
	ft_wcharlen.c\
	int_len.c\
	print_bin.c\
	print_char.c\
	print_hex.c\
	print_int.c\
	print_oct.c\
	print_percent.c\
	print_prec.c\
	print_ptr.c\
	print_str.c\
	print_uns_int.c\
	print_width.c\
	print_wstr.c\
	flags_uns_int.c\
	flags_int.c\
	ft_strdel.c \
	ft_strcmp.c

OBJ= $(FILES:.c=.o)

CC = gcc

HEADERS= includes
FLAGS= -Wall -Wextra -Werror

SRC = $(addprefix srcs/,$(FILES))
INCDIR= ./includes/
OBJDIR= ./obj/

all : $(NAME)

$(NAME) :
	@ $(CC) $(FLAGS) -I $(HEADERS) -c $(SRC)
	@ ar rc $(NAME) $(OBJ)
	@ ranlib $@
	@echo  '\x1b[42m' '\x1b[34m' " *================================*  " '\x1b[0m'
	@echo  '\x1b[42m' '\x1b[34m' " *                                *  " '\x1b[0m'
	@echo  '\x1b[42m' '\x1b[34m' " *  Compiling libftprintf.a... OK *  " '\x1b[0m'
	@echo  '\x1b[42m' '\x1b[34m' " *                                *  " '\x1b[0m'
	@echo  '\x1b[42m' '\x1b[34m' " *================================*  " '\x1b[0m'

clean :
	@rm -rf $(OBJ)
	@echo  '\x1b[43m' '\x1b[31m' " *================================*  " '\x1b[0m'
	@echo  '\x1b[43m' '\x1b[31m' " *                                *  " '\x1b[0m'
	@echo  '\x1b[43m' '\x1b[31m' " *  Cleaning Object files...   OK *  " '\x1b[0m'
	@echo  '\x1b[43m' '\x1b[31m' " *                                *  " '\x1b[0m'
	@echo  '\x1b[43m' '\x1b[31m' " *================================*  " '\x1b[0m'

fclean : clean
	@rm -f $(NAME)

re: fclean all
