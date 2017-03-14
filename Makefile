# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/25 16:12:54 by fdel-car          #+#    #+#              #
#    Updated: 2016/03/21 17:38:24 by fdel-car         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = src/fdf.c src/ft_color.c src/ft_draw.c src/ft_init.c src/ft_iso.c \
		src/ft_shortcut.c src/main.c

OBJS = fdf.o ft_color.o ft_draw.o ft_init.o ft_iso.o ft_shortcut.o main.o

CFLAGS = -Wall -Wextra -Werror

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJS)
	@make re -C libft
	@gcc  -I./includes $(MLXFLAGS) -o $@ $^ ./libft/libft.a
	@echo "\033[1;31m$(NAME) compiled successfully"
	@echo "\033[1A\033[0;39m"

$(OBJS): $(SRCS)
	@clang $(CFLAGS) -c $^ -I./libft/includes -I./includes

clean:
	@make clean -C libft
	@rm -rf $(OBJS)
fclean: clean
	@rm -rf $(NAME)

re: fclean
	make all

.PHONY: all clean fclean re
