# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/09 14:12:20 by youkim            #+#    #+#              #
#    Updated: 2021/10/17 15:41:18 by youkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ===== Target & FLAGS =====
NAME   = libft.a

LIBFT  = src/libft/y

CC     = gcc
CFLAGS = #-Wall -Wextra -Werror
AR     = ar rcs
RM     = rm -f

# ===== Raw Sources =====
SRR    = strlen

# ===== Sources & Objects & Includes =====
INC    = -I includes/
OBJ    = $(SRC:%.c=%.o)
SRC    = $(addprefix $(LIBFT), $(addsuffix .c, $(SRR)))

# ===== Macros =====
%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

$(NAME): $(OBJ)
	$(AR) $@ $^

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

test: all
	@./$(NAME)

.PHONY: all re clean fclean test