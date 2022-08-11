#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acastano <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/11 19:15:31 by acastano          #+#    #+#              #
#    Updated: 2022/08/11 19:23:28 by acastano         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_ls

CC = clang

CFLAGS = -Wall -Wextra -Werror

INCLUDES = -I ./libft/

LIB = -L ./libft -lft

SRC = main.c
#main.c error.c read_file.c convert_file.c build_struct.c map.c solver.c printer.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@make -C libft/ re
	$(CC) $(CFLAGS) $(INCLUDES) $(SRC) $(LIB) -o $(NAME)

clean:
	@make clean -C libft/
	/bin/rm -f *.o

fclean: clean
	@make fclean -C libft/
	/bin/rm -f $(NAME)

re: fclean all

.PHONY = all clean fclean re
