#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acastano <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/04 16:14:56 by acastano          #+#    #+#              #
#    Updated: 2022/08/25 13:37:16 by acastano         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc

CFLAGS = -Wall -Werror -Wextra

NAME = libft.a

SRCS = ft_strcmp.c ft_strdup.c ft_strlen.c ft_memdel.c ft_memcpy.c
#ft_putchar.c ft_putstr.c ft_strlen.c ft_putnbr.c ft_strclr.c ft_strequ.c ft_putendl.c ft_isalpha.c ft_tolower.c ft_toupper.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_atoi.c ft_strcmp.c ft_strncmp.c ft_strnequ.c ft_strstr.c ft_strnstr.c ft_memset.c ft_strcpy.c ft_strncpy.c ft_bzero.c ft_strdup.c ft_strcat.c ft_memcpy.c ft_memccpy.c ft_strchr.c ft_strrchr.c ft_strncat.c ft_strlcat.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_is_3whitespace.c ft_count_3whitespace_b.c ft_count_3whitespace_e.c ft_word_count.c ft_strlen_tochar.c

HEADERS = libft.h

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -c $(SRCS) -I$(HEADERS)
	ar -rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ) *.c~ *.h~

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY = all clean fclean re
