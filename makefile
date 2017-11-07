# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 14:51:07 by ssabbah           #+#    #+#              #
#    Updated: 2017/11/07 15:13:15 by ssabbah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= ft_printf

SRC= ft_printf.c\
	
OBJ= $(addprefix $(OBJDIR), $(SRC:.c=.o))

OBJDIR = ./obj/

CFLAGS= -Wall -Wextra -Werror

LIBFT= ./libft/libft.a
LIBINC= -I ./libft
LIBLINK= -L ./libft -lft

SRCDIR= ./src/
INCDIR= ./includes/
OBJDIR= ./obj/

all: $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	$(CC) $(LIBLINK) -o $(NAME) $(OBJ)

remlib:
	rm -rf $(LIBFT)

remoblib:
	make flcean -C ./libft/

clean: remoblib
	rm -rf $(NAME)

fclean: clean remlib
	rm -rf $(NAME)

re: fclean all
