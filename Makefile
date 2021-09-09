# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youkim <youkim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/09 14:12:20 by youkim            #+#    #+#              #
#    Updated: 2021/09/09 15:24:58 by youkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
CFLAGS = #-Wall -Wextra -Werror
RM = rm -rf

SRR = check_map
SRC = $(addprefix src/, $(addsuffix .c, $(SRR)))
OBJ = $(SRC:%.c=%.o)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

test: all
	@./$(NAME)

.PHONY: all re clean fclean test