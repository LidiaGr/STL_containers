# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttarsha <ttarsha@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/03 13:18:22 by ttarsha           #+#    #+#              #
#    Updated: 2021/02/19 17:10:05 by ttarsha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= containers

OBJS_DIR	= bin/
SRCS_DIR    = ./
SRCS		= main

OBJS		= $(addprefix $(OBJS_DIR), $(SRCS:=.o))

CC			= clang++
GCC_FLAGS	= -g -Wall -Wextra -Werror
INCLUDES	=   ./srcs/list.hpp \
				./srcs/vector.hpp \
				./srcs/stack.hpp \
				./srcs/queue.hpp \



all:			$(OBJS_DIR) $(NAME)

$(OBJS_DIR):
	mkdir -p	$(OBJS_DIR)

$(NAME):		$(OBJS)
	$(CC) 		-g $(OBJS) -o $(NAME)

$(OBJS):		$(OBJS_DIR)%.o: $(SRCS_DIR)%.cpp $(INCLUDES)
	$(CC)		$(GCC_FLAGS) -c $< -o $@


clean:
	rm -rf		$(OBJS_DIR)

fclean:			clean
	rm -f		$(NAME) $(TEST)

re:				fclean all


.PHONY: all clean fclean re