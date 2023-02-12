# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/08 16:46:56 by hdagdagu          #+#    #+#              #
#    Updated: 2023/02/12 16:45:03 by hdagdagu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c \

CC = cc

FLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.C=.o)

NAME = philo

LIBFT = libft
FT_PRINTF = ft_printf

$(NAME) : $(OBJ)
		make -C $(LIBFT)
		make -C $(FT_PRINTF)
		$(CC) $(OBJ) $(FLAGS) libft/libft.a ft_printf/libftprintf.a -o $(NAME)

%.o:%.c
	$(CC) $(FLAGS) -c $^ -o $@

all: $(NAME)

fclean:
	make fclean -C $(LIBFT)
	make fclean -C $(FT_PRINTF)
	rm -rf $(NAME) $(OBG)
	
clean:
	make clean -C $(LIBFT)
	make clean -C $(FT_PRINTF)
	rm -rf $(OBG)
	
re:fclean all