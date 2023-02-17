# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/08 16:46:56 by hdagdagu          #+#    #+#              #
#    Updated: 2023/02/17 12:44:27 by hdagdagu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = philo/main.c \
      philo/check.c \
      philo/check_arg.c

BONUS = philo_bonus/main_bonus.c

CC = cc

FLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(BONUS:.c=.o)

NAME = philo/philo

NAME_BONUS = philo_bonus/philo_bonus

LIBFT = philo/libft

RED = \033[31m
GREAN = \033[32m 
WHITE = \033[37m

TIMER_LENGTH = 15
TIMER_DELAY = 0.1

all: $(NAME)

$(NAME): $(OBJ)
	@make copy
	@make -C $(LIBFT)
	@$(CC) $(OBJ) $(FLAGS) $(LIBFT)/libft.a -o $(NAME)
	@echo "$(GREAN) make Mandatory is done  [✅] $(WHITE)"
	@sleep 1



$(NAME_BONUS): $(OBJ_BONUS)
	@make copy
	@make -C $(LIBFT)
	@$(CC) $(OBJ_BONUS) $(FLAGS) $(LIBFT)/libft.a -o $(NAME_BONUS)
	@echo "$(GREAN) make Bonus is done  [✅] $(WHITE)"
	@sleep 1

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@
	
bonus: $(NAME_BONUS)

copy:
	@echo "$(RED)"
	@i=0; while [ $$i -le $(TIMER_LENGTH) ]; do \
	    sleep $(TIMER_DELAY); \
	    printf "\r[%-$(TIMER_LENGTH)s]" "$$(printf '🦩%.0s' $$(seq 1 $$i))"; \
	    i=$$((i+1)); \
	done
	@echo "$(WHITE)"

clean: 
	@make copy
	@sleep 1
	@make clean -C $(LIBFT)
	@rm -rf $(OBJ)
	@echo "$(GREAN) Cleaning libft is done  [✅] $(WHITE)"
	@sleep 1
	@echo "$(GREAN) Cleaning philo is done  [✅] $(WHITE)"
	@sleep 1

fclean: clean
	@make fclean -C $(LIBFT)
	@rm -rf $(NAME) $(NAME_BONUS)

re: fclean all
