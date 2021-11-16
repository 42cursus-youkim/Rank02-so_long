# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/09 14:12:20 by youkim            #+#    #+#              #
#    Updated: 2021/11/16 16:19:20 by youkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ===== Target & FLAGS =====
NAME = so_long

CC ?= clang
CFLAGS ?= #-Wall -Wextra -Werror
RM ?= rm -rf

# ===== Sources =====
SRC = so_long #check_map

# ===== & Objects & Includes =====
INC = -I includes/ -I mlx -I lib/libft.a
MLX = -l mlx -framework OpenGL -framework Appkit
SRC = $(addprefix src/, $(addsuffix .c, $(SRR)))
OBJ = $(SRC:%.c=%.o)

# ===== Functions =====
define make_libft
	make all -C lib/
endef

# ===== Macros =====
%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

$(NAME): $(OBJ)
	$(call make_libft)
	$(CC) $(CFLAGS) $(INC) $(MLX) -o $@ $^

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

test: all
	@./$(NAME)

.PHONY: all re clean fclean test