# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/30 15:34:54 by tda-silv          #+#    #+#              #
#    Updated: 2022/09/02 15:30:53 by tda-silv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

CFLAGS = -Wall -Wextra -Werror

NAME_ONE = server

NAME_TWO = client

SRC_GLOBAL = ./libft/ft_atoi.c \
			 ./libft/ft_strlen.c \
			 ./libft/ft_itoa_two.c \
			 ./libft/ft_itoa_ten.c \
			 ./global_function/find_size_pid.c \
			 ./global_function/add_zero.c \
			 ./global_function/conv_size_bin.c \
			 ./global_function/setup_struct.c \
			 ./global_function/conv_oct_int.c \
			 ./t_li/li_add_back.c \
			 ./t_li/li_clear_one.c \
			 ./t_li/li_clear.c \
			 ./t_li/*li_last.c \
			 ./t_li/*li_new.c \
			 ./t_li/li_size.c \

SRC_ONE = ./server.c \
		  ./server_child/s_conv_str_bin.c \
		  ./server_child/s_send_signal.c \

SRC_TWO = ./client.c \
		  ./client_child/c_check_error.c \
		  ./client_child/c_conv_str_bin.c \
		  ./client_child/c_send_signal.c \

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
