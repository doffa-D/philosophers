# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/15 13:14:01 by hdagdagu          #+#    #+#              #
#    Updated: 2023/01/31 20:03:17 by hdagdagu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC = ft_printf.c \
	ft_put_hex.c \
	ft_putchar.c \
	ft_putstr.c \
	ft_putnbr.c \
	ft_unsi_putnbr.c \
	ft_put_addp.c \

CC = gcc
CFLAGS = -Wall -Werror -Wextra
OBJ = $(SRC:.c=.o)
NAME = libftprintf.a
AR = ar rcs

color =\033[0;35m
END=\033[0m

all:$(NAME)
	
$(NAME): $(OBJ)
	@$(AR) $@ $^
	@echo "$(color) [✅] ft_printf $(END)"

%.o:%.c
	@$(CC) $(CFLAGS) -c $^ -o $@ 

fclean:
	@rm -rf $(NAME) $(OBJ)
clean: 
	@rm -rf $(OBJ)
re:fclean $(NAME)
