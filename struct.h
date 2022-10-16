/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 10:00:26 by tda-silv          #+#    #+#             */
/*   Updated: 2022/10/15 21:26:01 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_list_int
{
	int					content;
	struct s_list_int	*prev;
	struct s_list_int	*next;
}	t_li;

typedef struct s_double_list
{
	int						content;
	struct s_double_list	*prev;
	struct s_double_list	*next;
	t_li					*prev_li;
	t_li					*next_li;
}	t_dl;

typedef struct s_s_data_minitalk
{
	int		pid_server;
	int		pid_client;
	t_dl	*client_connected;
}	t_s_data_minitalk;

typedef struct s_c_data_minitalk
{
	int		pid_server;
	int		pid_client;
	int		stock_signal;
	char	**str_bin;
}	t_c_data_minitalk;

#endif
