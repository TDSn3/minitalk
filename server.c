/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:37:06 by tda-silv          #+#    #+#             */
/*   Updated: 2022/10/11 15:07:02 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static t_s_data_minitalk	g_d;
static void	handler(int signal, siginfo_t *x, void *y);
void	show_list(t_dl	*list);

int	main(void)
{
	struct sigaction	ssa_a;
	
	s_setup_struct(&g_d);
	ssa_a.sa_sigaction = &handler;
	ssa_a.sa_flags = SA_SIGINFO;
	sigemptyset(&ssa_a.sa_mask);
	g_d.pid_server = getpid();
	ft_printf("\033[36mPid server : \033[36;04m%d\033[00m\n", g_d.pid_server);
	sigaction(SIGUSR1, &ssa_a, 0);
	sigaction(SIGUSR2, &ssa_a, 0);
	while (1)
		pause();
	return (0);
}

static void	handler(int signal, siginfo_t *x, void *y)
{
	t_li	*stock_li;
	
	(void) y;
	if (signal == 10)
	{
		if (g_d.i_signal % 8 == 0)
			g_d.i_zero = 0;
		g_d.stock_signal = 1;
		g_d.i_signal += 1;
		g_d.i_zero += 1;
		if (!dl_find_pid(g_d.client_connected, (int)(x->si_pid)))
		{
			dl_add_back(&g_d.client_connected, dl_new((int)(x->si_pid)));
			ft_printf("\033[33mNew pid client : \033[33;04m%d\033[00m\n", (int)(x->si_pid));
		}
		ft_printf("\033[34mSIGUSR1\033[34;02m received - 0   | i.zero = %d\t\t\ti.signal = %d  (%d)\033[00m\n", g_d.i_zero, g_d.i_signal,g_d.stock_signal);
		stock_li = dl_find_pid(g_d.client_connected, (int)(x->si_pid));
		if (!stock_li)
		{
			write(2, "\033[31;01mError - Client not found\033[00m\n", 40);
			exit(1);
		}
		li_add_back(&stock_li, li_new(0));
		s_check_null_li(&g_d.client_connected, (int)(x->si_pid));
		kill((int)(x->si_pid), 10);
		return ;
	}
	else if (signal == 12)
	{
		if (g_d.i_signal % 8 == 0)
			g_d.i_zero = 0;
		g_d.stock_signal = 2;
		g_d.i_signal += 1;
		if (!dl_find_pid(g_d.client_connected, (int)(x->si_pid)))
		{
			dl_add_back(&g_d.client_connected, dl_new((int)(x->si_pid)));
			ft_printf("\033[33mNew pid client : \033[33;04m%d\033[00m\n", (int)(x->si_pid));
		}
		ft_printf("\033[35mSIGUSR2\033[35;02m received - 1\t\t\t\t\ti.signal = %d  (%d)\033[00m\n", g_d.i_signal, g_d.stock_signal);
		stock_li = dl_find_pid(g_d.client_connected, (int)(x->si_pid));
		if (!stock_li)
		{
			write(2, "\033[31;01mError - Client not found\033[00m\n", 40);
			exit(1);
		}
		li_add_back(&stock_li, li_new(1));
		kill((int)(x->si_pid), 12);
		return ;
	}	
}

/*

Le serveur doit être lancé en premier, puis afficher son PID
ssa = Struct SigAction
ssi = Struct SigInfo

*/
