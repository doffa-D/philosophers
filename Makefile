# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/08 16:46:56 by hdagdagu          #+#    #+#              #
#    Updated: 2023/02/19 12:00:08 by hdagdagu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = philo/main.c \
      philo/check.c \
      philo/check_arg.c \
	  philo/philo.c \
	  philo/utils.c \

BONUS = philo_bonus/main_bonus.c \
		philo_bonus/philo_bonus.c \
      	philo/check.c \
      	philo/check_arg.c \
		philo/philo.c \
		philo/utils.c \


CC = cc

HD = philo/philo.h

HD_B = philo_bonus/philo_bonus.h

FLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(BONUS:.c=.o)

NAME = philo/philo

NAME_BONUS = philo_bonus/philo_bonus

RED = \033[31m
GREAN = \033[32m 
WHITE = \033[37m

TIMER_LENGTH = 20
TIMER_DELAY = 0.07

all: $(NAME)

$(NAME): $(OBJ) $(HD)
	@make copy
	@$(CC) $(OBJ) $(FLAGS) -o $(NAME)
	@echo "$(RED)DO🦩:$(GREAN)make Mandatory is done  [✅] $(WHITE)"
	@sleep $(TIMER_DELAY)



$(NAME_BONUS): $(OBJ_BONUS) $(HD_B)
	@make copy
	@$(CC) $(OBJ_BONUS) $(FLAGS)  -o $(NAME_BONUS)
	@echo "$(RED)DO🦩:$(GREAN)make Bonus is done  [✅] $(WHITE)"
	@sleep $(TIMER_DELAY)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@
	
bonus: $(NAME_BONUS)

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
	@rm -rf $(OBJ) $(OBJ_BONUS)
	@sleep $(TIMER_DELAY)
	@echo "$(RED)DO🦩:$(GREAN)Cleaning philo is done  [✅] $(WHITE)"
	@sleep $(TIMER_DELAY)

fclean: clean
	@rm -rf $(NAME) $(NAME_BONUS)

re: fclean all
