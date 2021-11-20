# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/09 14:12:20 by youkim            #+#    #+#              #
#    Updated: 2021/11/20 17:50:38 by youkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ===== Target & FLAGS =====
NAME     := libft.a

CC       := gcc
CFLAGS   := -Wall -Wextra -Werror -g3
VFLAGS   := --leak-check=full --show-leak-kinds=all \
			--track-origins=yes \
			--suppressions=./valgrind.suppressions \
			#--gen-suppressions=yes
AR       := ar -rcs
RM       := rm -f

PRE      := src/
INC      := -I includes/

# ===== Macros =====
define choose_modules
	$(foreach pkg, $(1),			\
		$(foreach file, $($(pkg)V),	\
			$(PRE)y$(pkg)/$(file).c	\
		)							\
	)
endef

# ===== Packages =====
PKGS     := string array system dict
arrayV   := new_yarr
stringV  := \
	new_ystr del_ystr				\
	ystrlen  ystr_color				\
	new_ystrjoin					\

systemV  := yexit yalloc ysyscall
dictV    := new_ydict del_ydict yhash #ydict_set ydict_get

# ===== Sources & Objects & Includes =====
SRC      := $(call choose_modules, $(PKGS))
OBJ      := $(SRC:%.c=%.o)

# ===== Recipes =====
%.o: %.c
	@echo  $(subst .c,.o, $(lastword $(subst /, , $<)))
	@$(CC) $(CFLAGS) $(INC) -c -o $@ $<

$(NAME): $(OBJ)
	@echo "$(V)<Archiving Object files...>$(E)"
	@$(AR) $@ $(OBJ)
	@echo "$(G)<<$(NAME)>>$(E)"

all: $(NAME)

clean:
	@$(RM) $(OBJ)
	@echo "$(Y)<Cleaned Object files>$(E)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(Y)<Cleaned Names>$(E)"

re: fclean all

# ===== Custom Recipes =====
red: fclean docs all
ald: docs all

docs:
	@echo "$(G)<Generating Documentation...>$(E)"
	@set -e;\
		for p in $(PKGS); do\
			../../protogen/run.py "" includes/y$$p.h src/y$$p;\
		done
	@echo "$(G)<Updated Docs>$(E)"

test: docs all
	@echo "$(Y)<Running Test>$(E)"
	@$(CC) $(INC) $(NAME) test.c -o test
	@./test
	@rm test

leak: docs all
	@echo "$(Y)<Running Leak Test>$(E)"
	@$(CC) $(INC) $(NAME) test.c -o test
	@colour-valgrind $(VFLAGS) ./test
	@rm test

.PHONY: all re clean fclean test red docs

# ===== Colors =====
Y ?= \033[0;33m
G ?= \033[0;32m
V ?= \033[0;35m
E ?= \033[0m