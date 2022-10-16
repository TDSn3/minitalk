/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_handler_kill_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:02:39 by tda-silv          #+#    #+#             */
/*   Updated: 2022/10/16 01:06:12 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

static void	add_signal_kill(t_dl **c_c, int pid, int signal, t_li *stock_li);

void	s_handler_kill_bonus(t_dl **client_connected, int pid, int signal)
{
	t_li	*stock_li;
	t_dl	*new_dl;

	if (!dl_find_pid(*client_connected, pid))
	{
		new_dl = dl_new(pid);
		if (!new_dl)
			exit(clear_error_exit(client_connected, 1));
		dl_add_back(client_connected, new_dl);
		ft_printf("\033[33mNew pid client :");
		ft_printf(" \033[33;04m%d\033[00m\n", pid);
	}
	stock_li = dl_find_pid(*client_connected, pid);
	if (!stock_li)
		exit(clear_error_exit(client_connected, 2));
	add_signal_kill(client_connected, pid, signal, stock_li);
}

static void	add_signal_kill(t_dl **c_c, int pid, int signal, t_li *stock_li)
{
	t_li	*new_li;

	new_li = NULL;
	if (signal == 10)
		new_li = li_new(0);
	else if (signal == 12)
		new_li = li_new(1);
	if (!new_li)
		exit(clear_error_exit(c_c, 1));
	li_add_back(&stock_li, new_li);
	if (signal == 10)
	{
		ft_printf("\033[34mSIGUSR1\033[34;02m received - 0\033[00m\n");
		s_check_null_li(c_c, pid);
		kill(pid, 10);
	}
	else if (signal == 12)
	{
		ft_printf("\033[35mSIGUSR2\033[35;02m received - 1\033[00m\n");
		kill(pid, 12);
	}
}
