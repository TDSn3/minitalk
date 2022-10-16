# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/30 15:34:54 by tda-silv          #+#    #+#              #
#    Updated: 2022/10/16 01:59:12 by tda-silv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

CFLAGS = -Wall -Wextra -Werror

NAME_ONE = server

NAME_TWO = client

BNS = bonus_ok

HEADERS = ./header.h \
		  ./struct.h \
		  ./libft/libft.h \
		  ./global_function/global_function.h \
		  ./t_li/t_li.h \
		  ./t_dl/t_dl.h \
		  ./server_child/server_child.h \
		  ./client_child/client_child.h \
		  ./bonus/client_child_bonus/client_child_bonus.h \
		  ./bonus/server_child_bonus/server_child_bonus.h \

SRC_GLOBAL = ./libft/ft_atoi.c \
			 ./libft/ft_strlen.c \
			 ./libft/ft_itoa_two.c \
			 ./libft/n_under_zero.c \
			 ./libft/ft_itoa_ten.c \
			 ./libft/ft_strjoin.c \
			 ./libft/ft_strlcpy.c \
			 ./libft/ft_swap.c \
			 ./libft/ft_swap_index.c \
			 ./libft/ft_cpy.c \
			 ./global_function/add_zero.c \
			 ./global_function/conv_oct_int.c \
			 ./global_function/conv_str_bin.c \
			 ./global_function/clear_error_exit.c \
			 ./t_li/li_add_back.c \
			 ./t_li/li_clear_one.c \
			 ./t_li/li_clear.c \
			 ./t_li/li_last.c \
			 ./t_li/li_new.c \
			 ./t_li/li_size.c \
			 ./t_li/li_find_pid.c \
			 ./t_dl/dl_new.c \
			 ./t_dl/dl_add_back.c \
			 ./t_dl/dl_clear.c \
			 ./t_dl/dl_find_pid.c \
			 ./t_dl/dl_size.c \
			 ./t_dl/dl_last.c \
			 ./t_dl/dl_clear_one.c \

SRC_ONE = ./server.c
SRC_TWO = ./client.c

SRC_CHILD = ./client_child/c_check_error.c \
			./client_child/c_setup_struct.c \
			./client_child/c_send_str_signal.c \
			./server_child/s_setup_struct.c \
			./server_child/s_check_null_li.c \
			./server_child/s_handler_kill.c \

BNS_CHILD = ./bonus/client_child_bonus/c_send_str_signal_bonus.c \
			./bonus/server_child_bonus/s_handler_kill_bonus.c \

BNS_ONE = ./bonus/server_bonus.c 
BNS_TWO = ./bonus/client_bonus.c 

OBJ_GLOBAL = $(SRC_GLOBAL:.c=.o)
OBJ_ONE = $(SRC_ONE:.c=.o)
OBJ_TWO = $(SRC_TWO:.c=.o)
OBJ_CHILD = $(SRC_CHILD:.c=.o)
OBJ_BNS_ONE = $(BNS_ONE:.c=.o)
OBJ_BNS_TWO = $(BNS_TWO:.c=.o)
OBJ_BNS_CHILD = $(BNS_CHILD:.c=.o)

all: $(NAME_ONE) $(NAME_TWO) $(HEADERS)

$(NAME_ONE): $(OBJ_ONE) $(OBJ_GLOBAL) $(OBJ_CHILD)
	cd ./ft_printf; make
	$(CC) $(CFLAGS) -o $(NAME_ONE) $^ ./ft_printf/libftprintf.a

$(NAME_TWO): $(OBJ_TWO) $(OBJ_GLOBAL) $(OBJ_CHILD)
	cd ./ft_printf; make
	$(CC) $(CFLAGS) -o $(NAME_TWO) $^ ./ft_printf/libftprintf.a

bonus: $(BNS)

$(BNS): $(OBJ_BNS_ONE) $(OBJ_BNS_TWO) $(OBJ_BNS_CHILD) $(OBJ_GLOBAL) $(OBJ_CHILD)
	cd ./ft_printf; make
	touch bonus_ok
	$(CC) $(CFLAGS) -o $(NAME_ONE) $(OBJ_BNS_ONE) $(OBJ_BNS_CHILD) $(OBJ_GLOBAL) $(OBJ_CHILD) ./ft_printf/libftprintf.a
	$(CC) $(CFLAGS) -o $(NAME_TWO) $(OBJ_BNS_TWO) $(OBJ_BNS_CHILD) $(OBJ_GLOBAL) $(OBJ_CHILD) ./ft_printf/libftprintf.a

clean:
	cd ./ft_printf; make clean
	rm -f $(OBJ_ONE) $(OBJ_TWO) $(OBJ_GLOBAL) $(OBJ_CHILD) $(OBJ_BNS_ONE) $(OBJ_BNS_TWO) $(OBJ_BNS_CHILD)

fclean: clean
	cd ./ft_printf; make fclean
	rm -f $(NAME_ONE) $(NAME_TWO)
	touch bonus_ok
	rm bonus_ok

re: fclean all

.PHONY: all clean fclean re bonus
