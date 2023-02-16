# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/08 16:46:56 by hdagdagu          #+#    #+#              #
#    Updated: 2023/02/16 18:37:10 by hdagdagu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c \
	check.c \
	check_arg.c \

CC = cc

FLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.C=.o)

NAME = philo

LIBFT = libft

$(NAME) : $(OBJ)
		make -C $(LIBFT)
		$(CC) $(OBJ) $(FLAGS) libft/libft.a -o $(NAME)

%.o:%.c
	$(CC) $(FLAGS) -c $^ -o $@

all: $(NAME)

fclean:
	make fclean -C $(LIBFT)
	rm -rf $(NAME) $(OBG)
	
clean:
	make clean -C $(LIBFT)
	rm -rf $(OBG)
	
re:fclean all