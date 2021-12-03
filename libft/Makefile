# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/09 14:12:20 by youkim            #+#    #+#              #
#    Updated: 2021/12/03 11:01:19 by youkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ===== Target & FLAGS =====
NAME     := libft.a

CC       := gcc
CFLAGS   := -Wall -Wextra -Werror #-g
VFLAGS   := --leak-check=full --show-leak-kinds=all \
			--track-origins=yes \
			--suppressions=./macos.supp
AR       := ar -rcs
RM       := rm -f

PRE      := src/
INC      := -I includes/

# ===== Packages =====
PKGS     := string system dict math #linked

mathV  := \
	func_ymath new_yitoa

systemV  := \
	yexit yalloc ysyscall ylog ygnl

stringV  := \
	new_ystr new_ystrjoin new_ysplit	\
	del_ystr mod_ystr func_ystr			\

dictV    := \
	new_ydict del_ydict yhash			\
	ydict_set ydict_get	ydict_expand	\
	ydict_property ydict_status			\
	ycharmap

linkedV  := \
	new_ylist func_ylist
#new_ydeque

# ===== Macros =====
define choose_modules
	$(foreach pkg, $(1),			\
		$(foreach file, $($(pkg)V),	\
			$(PRE)y$(pkg)/$(file).c	\
		)							\
	)
endef

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
			../../hgen/run.py "" includes/y$$p.h src/y$$p;\
		done
	@echo "$(G)<Updated Docs>$(E)"

testdry: docs all
	@echo "$(Y)<Running Test>$(E)"
	@$(CC) $(INC) $(NAME) test.c -o test
	@echo "$(G)<Compiled Test>$(E)"

test: testdry
	@./test
	@rm test
	@echo "$(G)<Ended Test>$(E)"

leak: docs all
	@echo "$(Y)<Running Leak Test>$(E)"
	@$(CC) $(INC) $(NAME) test.c -o test
	@colour-valgrind $(VFLAGS) ./test
	@rm test

leaksup: docs all
	@echo "$(Y)<Creating Leak Suppressions>$(E)"
	@$(CC) $(INC) $(NAME) test.c -o test
	@valgrind $(VFLAGS) --gen-suppressions=yes ./test
	@rm test

.PHONY: all re clean fclean test red docs

# ===== Colors =====
Y ?= \033[0;33m
G ?= \033[0;92m
V ?= \033[0;35m
E ?= \033[0m