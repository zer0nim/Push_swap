# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emarin <emarin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/12 11:20:07 by emarin            #+#    #+#              #
#    Updated: 2018/01/19 19:05:25 by emarin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ARG = 5 3 2 1 9

NAME1 = checker
NAME2 = push_swap

SRC_NAME1 = ft_checker.c \
			ft_util.c \
			ft_pile.c \
			ft_op.c \
			ft_check.c \
			pile_utils.c

SRC_NAME2 = ft_push_swap.c \
			ft_util.c \
			ft_pile.c \
			ft_op.c \
			ft_check.c \
			sort_utils.c \
			sort_utils2.c \
			pile_utils.c \
			ft_insert_sort.c \
			ft_min_sort.c \
			ft_merge_sort.c \
			ft_merge_sort2.c

SRC_PATH = src

OBJ_PATH = obj

OBJ_NAME1 = $(SRC_NAME1:.c=.o)
OBJ_NAME2 = $(SRC_NAME2:.c=.o)

SRC1 = $(addprefix $(SRC_PATH)/,$(SRC_NAME1))
SRC2 = $(addprefix $(SRC_PATH)/,$(SRC_NAME2))

OBJ1 = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME1))
OBJ2 = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME2))

FLAGS = -Wall -Wextra -Werror

LIBFT = libft/libftprintf.a

HEADERS = -I ./

all: $(NAME1) $(NAME2)

$(LIBFT) : |
	@MAKE -C libft

$(NAME1): $(LIBFT) $(OBJ1)
	gcc -o $(NAME1) $(OBJ1) $(LIBFT)

$(NAME2): $(OBJ2)
	gcc -o $(NAME2) $(OBJ2) $(LIBFT)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c ft_push_swap.h
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	gcc -c $(FLAGS) -o $@ -c $<

clean:
	make -C libft/ clean
	rm -f $(OBJ1)
	rm -f $(OBJ2)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME1) $(NAME2)

test:
	@./$(NAME2) $(ARG) | wc -l | sed "s/ //g" | tr "\n" "\t"
	@./$(NAME2) $(ARG) | ./$(NAME1) $(ARG) | sed "s/KO/KO >>> FAIL!!!/g"

re: fclean all

.PHONY: all, clean, fclean, re
