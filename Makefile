# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/30 15:34:54 by tda-silv          #+#    #+#              #
#    Updated: 2022/08/31 16:18:27 by tda-silv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

CFLAGS = -Wall -Wextra -Werror

NAME_ONE = server

NAME_TWO = client

SRC_GLOBAL = ./libft/ft_atoi.c \
			 ./libft/ft_strlen.c \
			 ./libft/ft_itoa.c \

SRC_ONE = ./server.c

SRC_TWO = ./client.c \
		  ./client_child/c_check_error.c \

OBJ_GLOBAL = $(SRC_GLOBAL:.c=.o)

OBJ_ONE = $(SRC_ONE:.c=.o)

OBJ_TWO = $(SRC_TWO:.c=.o)

all: $(NAME_ONE) $(NAME_TWO)

$(NAME_ONE): $(OBJ_ONE) $(OBJ_GLOBAL)
	$(CC) $(CFLAGS) -o $(NAME_ONE) $^
	
$(NAME_TWO): $(OBJ_TWO) $(OBJ_GLOBAL)
	$(CC) $(CFLAGS) -o $(NAME_TWO) $^

clean:
	rm -f $(OBJ_ONE) $(OBJ_TWO) $(OBJ_GLOBAL)

fclean: clean
	rm -f $(NAME_ONE) $(NAME_TWO)

re: fclean all

.PHONY: all clean fclean re
