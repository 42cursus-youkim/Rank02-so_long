# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/09 14:12:20 by youkim            #+#    #+#              #
#    Updated: 2021/12/03 11:30:38 by youkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ===== Target & FLAGS =====
NAME     := so_long

CC       := gcc
CFLAGS   := -g -Wall -Wextra -Werror -fsanitize=address
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

TEST     := ./so_long map/map3.ber

# ===== Packages =====
PKGS     := engine map utils
engineV  := so_long initialize updates images \
            player enemy_bonus enemies_bonus turn
mapV     := new_map del_map render render_utils valdidate
utilsV   := vectors colors utils texts

# ===== Macros =====
define choose_modules
	$(foreach pkg, $(1),\
		$(foreach file, $($(pkg)V),\
			$(PRE)$(pkg)/$(file).c\
		)\
	)
endef

define build_library
	@echo "$(Y)<Building Library>$(E)"
	@make all -C libft/
	@echo "$(G)<Built Library>$(E)"
endef

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
			../hgen/run.py "" includes/$$p.h src/$$p;\
		done
	@echo "$(G)<Updated Docs>$(E)"

test: docs all
	@echo "$(Y)<Running Test>$(E)"
	@$(TEST)
	@echo "$(G)<Ended Test>$(E)"

leak: docs all
	@echo "$(Y)<Running Leak Test>$(E)"
	@colour-valgrind $(VFLAGS) $(TEST)
	@rm so_long

leaksupp: docs all
	@echo "$(Y)<Creating Leak Suppressions>$(E)"
	@valgrind $(VFLAGS) $(VSFLAGS) $(TEST)
	@rm so_long

leaks: docs all
	@echo "$(Y)<Info for Leaks>$(E)"
	@$(TEST) &
	@set -e; \
	PID=$$(ps -U $$USER | grep -i so_long | \
			grep -v grep | cut -d ' ' -f 1) ;\
		echo "so_long: $$PID" ;\
		pbcopy <<< "leakchk $$PID" ;\

# @$(CC) $(INC) $(NAME) test.c -o test

.PHONY: all re clean fclean red ald test leak leaksupp leaks

# ===== Colors =====
Y ?= \033[0;33m
G ?= \033[0;92m
V ?= \033[0;35m
E ?= \033[0m