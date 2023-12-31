# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/16 18:20:23 by kglebows          #+#    #+#              #
#    Updated: 2023/11/09 14:17:49 by kglebows         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

CFLAGS_MLX := -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX := ./lib/MLX42

HEADERS := -I ./include -I $(LIBMLX)/include


LIBFTNAME = bin/libft/libft.a
LIBFTDIR = src/libft
OBJDIR = ./bin
SRCDIR = ./src

LIBMLXA := $(LIBMLX)/build/libmlx42.a
MLX_PATH := lib/MLX42

HEADERS	:= -I ./include -I $(LIBMLX)/include
LIB_MLX	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRC_MLX	:= $(shell find ./src -iname "*.c")
OBJ_MLX := ${SRC_MLX:.c=.o}

SRCS	= main.c \
		ini/error.c ini/ini.c ini/map.c ini/utils.c \
		vis/background.c vis/utility.c vis/frame.c \
		vis/mlx_handler.c vis/mlx_load.c vis/mlx_string.c \
		game/enemy.c game/ft_pos.c game/move.c game/random.c \
		exit/exit.c 
OBJS	= $(SRCS:%.c=$(OBJDIR)/%.o)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	@OUTPUT=$$($(CC) $(CFLAGS) -Isrc -c $< -o $@ 2>&1); \
	if [ $$? -eq 0 ]; then \
		echo "\033[0;32m$< OK!\033[0m"; \
	else \
		echo "$$OUTPUT" && echo "\033[0;31m$< KO!\033[0m" && exit 1; \
	fi

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

all: init-submodules $(NAME)

init-submodules:
	@if [ -z "$(shell ls -A $(MLX_PATH))" ]; then \
		git submodule init $(MLX_PATH); \
		git submodule update $(MLX_PATH); \
	fi

$(LIBMLXA):
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

makelibft:
	@if [ ! -f "$(LIBFTNAME)" ]; then \
		OUTPUT=$$(make -C $(LIBFTDIR) --no-print-directory 2>&1); \
		if echo "$$OUTPUT" | grep -E "cc|ar" > /dev/null; then \
			echo "\033[0;32mLIBFT OK!\033[0m"; \
		fi; \
	fi

$(NAME): makelibft $(LIBMLXA) $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB_MLX) $(HEADERS) -L$(OBJDIR)/libft -lft

clean-empty-dirs:
	@if [ -d $(OBJDIR) ]; then find $(OBJDIR) -type d -empty -exec rmdir {} +; fi

clean: 
	@for obj in $(OBJS); do \
		if [ -f "$$obj" ]; then \
			rm -f $$obj && echo "\033[0;33m$$obj deleted\033[0m"; \
		fi; \
	done
	@OUTPUT=$$(make -C $(LIBFTDIR) clean --no-print-directory 2>&1); \
	if echo "$$OUTPUT" | grep -E "deleted" > /dev/null; then \
		echo "\033[0;33mlibft *.o deleted\033[0m"; \
	fi
	@$(MAKE) clean-empty-dirs
	@rm -rf $(LIBMLX)/build

fclean: clean
	@if [ -f "$(NAME)" ]; then \
		rm -f $(NAME) && echo "\033[0;33m$(NAME) deleted\033[0m"; \
	fi
	@OUTPUT=$$(make -C $(LIBFTDIR) fclean --no-print-directory 2>&1); \
	if echo "$$OUTPUT" | grep -E "deleted" > /dev/null; then \
		echo "\033[0;33mlibft.a deleted\033[0m"; \
	fi
	@$(MAKE) clean-empty-dirs

re: fclean all

.PHONY: all clean fclean norm re bonus