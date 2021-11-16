# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/09 14:12:20 by youkim            #+#    #+#              #
#    Updated: 2021/11/16 17:18:42 by youkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ===== Target & FLAGS =====
NAME   ?= libft.a
PRE    ?= src/libft/

CC     := gcc
CFLAG  := -Wall -Wextra -Werror
AR     := ar rcs
RM     ?= rm -f

# ===== Colors =====
R      ?= \033[1;31m
Y      ?= \033[0;33m
G      ?= \033[0;32m
V	   ?= \033[0;35m
E      ?= \033[0m

# ===== Raw Sources =====
ARR    ?= $(addprefix array/, )
STR    ?= $(addprefix string/, ystrlen)
SRR    += $(STR) $(ARR)

# ===== Sources & Objects & Includes =====
INC    = -I includes/
OBJ    = $(SRC:%.c=%.o)
SRC    = $(addprefix $(PRE), $(addsuffix .c, $(SRR)))

# ===== Macros =====
%.o: %.c
	@echo "$(V)<Compiling Object files...>$(E)"
	@echo $(SRR)
	@$(CC) $(CFLAGS) $(INC) -c -o $@ $<

$(NAME): $(OBJ)
	@echo "$(V)<Archiving Object files...>$(E)"
	@$(AR) $@ $^
	@echo "$(G)<DONE>$(E)"

all: $(NAME)

clean:
	@$(RM) $(OBJ)
	@echo "$(Y)<Cleaned Object files>$(E)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(Y)<Cleaned Namees>$(E)"

re: fclean all

test: all
	@./$(NAME)

.PHONY: all re clean fclean test