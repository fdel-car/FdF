#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdel-car <fdel-car@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/23 11:18:23 by fdel-car          #+#    #+#              #
#    Updated: 2016/02/29 17:44:24 by fdel-car         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

SRCS = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
	   ft_isdigit.c ft_isprint.c ft_memalloc.c ft_memccpy.c ft_memchr.c\
	   ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strcat.c ft_strchr.c\
	   ft_strcmp.c ft_strcpy.c ft_strdup.c ft_strlcat.c ft_strlen.c ft_strncat.c\
	   ft_strncmp.c ft_strncpy.c ft_strnstr.c ft_strrchr.c ft_strstr.c\
	   ft_tolower.c ft_toupper.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c\
	   ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c\
	   ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c\
	   ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c\
	   ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c\
	   ft_lstdel.c ft_lstadd.c ft_lstaddend.c ft_lstiter.c ft_lstmap.c\
	   ft_swap.c ft_islower.c ft_isupper.c ft_lstaddn.c ft_swap_string.c\
	   ft_putstr_lst.c ft_strndup.c ft_strjoin_free.c get_next_line.c\
	   ft_strputtab.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $@ $^
	ranlib $@

%.o: %.c
	@gcc $(CFLAGS) -c $^ -I./includes

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean
	make all
