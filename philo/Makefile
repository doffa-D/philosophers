# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/19 18:28:33 by hdagdagu          #+#    #+#              #
#    Updated: 2023/04/01 15:58:24 by hdagdagu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC =	main.c \
		utils.c \
		action.c \
		check_arg.c \
		check_rotin.c \
		creat_thread.c \
		free_all.c \
		initialize.c \

CC =  cc -Wall -Werror -Wextra

HD = philo.h


FLAGS = 

OBJ = $(SRC:.c=.o)

NAME = philo

RED = \033[31m
GREAN = \033[32m 
WHITE = \033[37m

TIMER_LENGTH = 20
TIMER_DELAY = 0.07

all: $(NAME)

$(NAME): $(OBJ) $(HD)
	@make copy
	@$(CC) $(OBJ) $(FLAGS) -o $(NAME)
	@echo "$(RED)DO🦩:$(GREAN) Mandatory is Ready  [✅] $(WHITE)"
	@sleep $(TIMER_DELAY)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@
	
copy:
	@echo "$(RED)"
	@printf "DO🦩: ["; \
	i=0; while [ $$i -le $(TIMER_LENGTH) ]; do \
	    sleep $(TIMER_DELAY); \
	    printf "▇"; \
	    i=$$((i+1)); \
	done
	@printf "] $(GREEN)100%%$(WHITE)\n"


clean: 
	@make copy
	@sleep $(TIMER_DELAY)
	@rm -rf $(OBJ)
	@sleep $(TIMER_DELAY)
	@echo "$(RED)DO🦩:$(GREAN)Cleaning philo is done  [✅] $(WHITE)"
	@sleep $(TIMER_DELAY)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
