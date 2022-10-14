/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_handler_kill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:02:39 by tda-silv          #+#    #+#             */
/*   Updated: 2022/10/14 19:03:31 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void add_signal_kill(t_dl **c_c, int pid, int signal, t_li *stock_li);

void s_handler_kill(t_dl **client_connected, int pid, int signal)
{
	t_li	*stock_li;
	t_dl	*new_dl;

	if (!dl_find_pid(*client_connected, pid))
	{
		new_dl = dl_new(pid);
		if (!new_dl)
			exit(clear_error_exit(client_connected, 1));
		dl_add_back(client_connected, new_dl);
	}
	stock_li = dl_find_pid(*client_connected, pid);
	if (!stock_li)
			exit(clear_error_exit(client_connected, 2));
	add_signal_kill(client_connected, pid, signal, stock_li);
}

static void add_signal_kill(t_dl **c_c, int pid, int signal, t_li *stock_li)
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
		s_check_null_li(c_c, pid);
		kill(pid, 10);	
	}
	else if (signal == 12)
		kill(pid, 12);	
}