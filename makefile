# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 14:51:07 by ssabbah           #+#    #+#              #
#    Updated: 2017/11/13 17:11:36 by ssabbah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= ft_printf

SRC= 	ft_printf.c\
	ft_convert.c\
	ft_putsign.c\

OBJ= $(addprefix $(OBJDIR), $(SRC:.c=.o))

CC= gcc

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
	$(CC) $(CFLAGS) $(LIBINC) -I $(INCDIR) -o $@ -c $<

libft: $(LIBFT)

$(LIBFT):
	make -C ./libft

$(NAME): obj libft $(OBJ)
	$(CC) $(LIBLINK) -o $(NAME) $(OBJ)

remlib:
	rm -rf $(LIBFT)

remoblib:
	make fclean -C ./libft/

clean: remoblib
	rm -rf $(NAME)

fclean: clean remlib
	rm -rf $(NAME)

re: fclean all
