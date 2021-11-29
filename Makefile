# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/09 14:12:20 by youkim            #+#    #+#              #
#    Updated: 2021/11/29 18:07:19 by youkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ===== Target & FLAGS =====
NAME     := so_long

CC       := gcc
CFLAGS   := #-g3 #-Wall -Wextra -Werror
VFLAGS   := --leak-check=full --show-leak-kinds=all \
			--track-origins=yes --show-reachable=no \
			--suppressions=./libft/macos.supp \
			--suppressions=./mlx.supp
VSFLAGS  := --show-reachable=yes --error-limit=no --gen-suppressions=all \
			# --log-file=./mlx.supp
RM       := rm -rf

PRE      := src/
INC      := -I includes/ -I mlx
MLX      := -l mlx -framework OpenGL -framework Appkit
LIBFT    := libft/libft.a
# ===== Macros =====
define choose_modules
	$(foreach pkg, $(1),\
		$(foreach file, $($(pkg)V),\
			$(PRE)$(pkg)/$(file).c\
		)\
	)
endef

define build_library
	@make all -C libft/
	@echo "$(G)<Built Library>$(E)"
endef

# ===== Packages =====
PKGS     := engine map
engineV  := so_long hooks render initialize
mapV     := #tiles #check_map

# ===== Sources & Objects & Includes =====
SRC      := $(call choose_modules, $(PKGS))
OBJ      := $(SRC:%.c=%.o)

# ===== Recipes =====
%.o: %.c
	@echo  $(subst .c,.o, $(lastword $(subst /, , $<)))
	@$(CC) $(CFLAGS) $(INC) -c -o $@ $<

$(NAME): $(OBJ)
	@$(call build_library)
	@$(CC) $(CFLAGS) $(INC) $(LIBFT) $(MLX) -o $@ $^
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
			../protogen/run.py "" includes/$$p.h src/$$p;\
		done
	@echo "$(G)<Updated Docs>$(E)"

test: docs all
	@echo "$(Y)<Running Test>$(E)"
	@./so_long
	@echo "$(G)<Ended Test>$(E)"

leak: docs all
	@echo "$(Y)<Running Leak Test>$(E)"
	@colour-valgrind $(VFLAGS) ./so_long
	@rm so_long

leaksupp: docs all
	@echo "$(Y)<Creating Leak Suppressions>$(E)"
	@valgrind $(VFLAGS) $(VSFLAGS) ./so_long
	@rm so_long

leaks: docs all
	@echo "$(Y)<Info for Leaks>$(E)"
	@./so_long &
	ps -U $(USER) | grep -i so_long

# @$(CC) $(INC) $(NAME) test.c -o test

.PHONY: all re clean fclean test

# ===== Colors =====
Y ?= \033[0;33m
G ?= \033[0;92m
V ?= \033[0;35m
E ?= \033[0m