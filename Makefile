# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/16 18:20:23 by kglebows          #+#    #+#              #
#    Updated: 2023/09/22 15:55:26 by kglebows         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBMLX := ./MLX42

HEADERS := -I ./include -I $(LIBMLX)/include


LIBFTNAME = bin/libft/libft.a
LIBFTDIR = src/libft
OBJDIR = ./bin
SRCDIR = ./src

HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
# SRCS	= $(shell find ./src -iname "*.c")
SRCS = main.c
OBJS	= $(SRCS:%.c=$(OBJDIR)/%.o)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	@OUTPUT=$$($(CC) $(CFLAGS) -Isrc -c $< -o $@ 2>&1); \
	if [ $$? -eq 0 ]; then \
		echo "\033[0;32m$< OK!\033[0m"; \
	else \
		echo "$$OUTPUT" && echo "\033[0;31m$< KO!\033[0m" && exit 1; \
	fi

all: makelibft $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

makelibft:
	@if [ ! -f "$(LIBFTNAME)" ]; then \
		OUTPUT=$$(make -C $(LIBFTDIR) --no-print-directory 2>&1); \
		if echo "$$OUTPUT" | grep -E "cc|ar" > /dev/null; then \
			echo "\033[0;32mLIBFT OK!\033[0m"; \
		fi; \
	fi

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(OBJDIR)/libft -lft

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