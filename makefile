# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/29 10:48:28 by ssabbah           #+#    #+#              #
#    Updated: 2017/11/30 17:06:09 by ssabbah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libftprintf.a

SRC= 	ft_printf.c\
		ft_convert.c\
		ft_putsign.c\
		print_fmt.c\
		flags.c\

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

clean:
	@echo "Deleting Objects"
	rm -rf ./libft/*.o
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(LIBFT)
	rm -rf $(NAME)

re: fclean all
