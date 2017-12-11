# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/29 10:48:28 by ssabbah           #+#    #+#              #
#    Updated: 2017/12/11 17:03:46 by ssabbah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libftprintf.a

SRC= 	ft_printf.c\
		ft_convert.c\
		ft_putsign.c\
		ft_fmt.c\
		print_fmt.c\
		print_flags.c\
		print_width.c\
		print_bin.c\
		print_ptr.c\
		print_oct.c\
		print_hex.c\
		print_int.c\

H_DIR = includes
C_DIR = src
O_DIR = objects

LINKS = -I$(H_DIR)

C_FILES = $(shell find $(C_DIR) -type f | grep "\.c")

O_FILES = $(C_FILES:$(C_DIR)/%.c=$(O_DIR)/%.o)

FLAGS = -Werror -Wextra -Wall

all: $(NAME)

$(NAME): $(O_FILES)
		@ar rcs $@ $^

$(O_DIR)/%.o: $(C_DIR)/%.c
		@mkdir -p $(O_DIR)
			@gcc $(FLAGS) $(LINKS) -o $@ -c $<

clean:
		@echo "Deleting Objects..."
			rm -rf $(O_DIR)


fclean: clean
		@echo "Deleting libftprintf.a..."
			@rm -f $(NAME)

re : fclean all

