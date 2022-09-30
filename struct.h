/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 10:00:26 by tda-silv          #+#    #+#             */
/*   Updated: 2022/09/30 12:21:29 by tda-silv         ###   ########.fr       */
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
/*

pid_server
pid_client
i_signal			- compte les signaux 
stock_signal		- stocke le signal reçus
i_zero				- compte les signaux égale zero
client_connected	- liste les clients connectés

*/
typedef struct  s_s_data_minitalk
{
	int		pid_server;
	int		pid_client;
	int		i_signal;
	int		stock_signal;
	int		i_zero;
	t_li	*client_connected;
}   t_s_data_minitalk;

typedef struct  s_c_data_minitalk
{
	int	pid_server;
	int	pid_client;
}   t_c_data_minitalk;

#endif
