/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:37:06 by tda-silv          #+#    #+#             */
/*   Updated: 2022/10/13 18:18:45 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static t_s_data_minitalk	g_d;
static void	handler(int signal, siginfo_t *x, void *y);

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
	sigaction(SIGINT, &ssa_a, 0);
	while (1)
		pause();
	return (0);
}

static void	handler(int signal, siginfo_t *x, void *y)
{
	t_li	*stock_li;
	t_dl	*new_dl;
	
	(void) y;
	if (signal == 2)
	{
		dl_clear(&g_d.client_connected);
		exit (0);
	}
	if (signal == 10)
	{
		if (g_d.i_signal % 8 == 0)
			g_d.i_zero = 0;
		g_d.stock_signal = 1;
		g_d.i_signal += 1;
		g_d.i_zero += 1;
		if (!dl_find_pid(g_d.client_connected, (int)(x->si_pid)))
		{
			new_dl = dl_new((int)(x->si_pid));
			if (!new_dl)
			{
				dl_clear(&g_d.client_connected);
				write(2, "\033[31;01mError - Malloc failled\033[00m\n", 38);
				exit (1);
			}
			dl_add_back(&g_d.client_connected, new_dl);
			ft_printf("\033[33mNew pid client : \033[33;04m%d\033[00m\n", (int)(x->si_pid));
		}
		ft_printf("\033[34mSIGUSR1\033[34;02m received - 0   | i.zero = %d\t\t\ti.signal = %d  (%d)\033[00m\n", g_d.i_zero, g_d.i_signal,g_d.stock_signal);
		stock_li = dl_find_pid(g_d.client_connected, (int)(x->si_pid));
		if (!stock_li)
		{
			dl_clear(&g_d.client_connected);
			write(2, "\033[31;01mError - Client not found\033[00m\n", 40);
			exit(1);
		}
		stock_li = li_new(0);
		if (!stock_li)
		{
			dl_clear(&g_d.client_connected);
			write(2, "\033[31;01mError - Client not found\033[00m\n", 40);
			exit(1);
		}
		li_add_back(&stock_li, stock_li);
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
			new_dl = dl_new((int)(x->si_pid));
			if (!new_dl)
			{
				dl_clear(&g_d.client_connected);
				write(2, "\033[31;01mError - Malloc failled\033[00m\n", 38);
				exit (1);
			}
			dl_add_back(&g_d.client_connected, new_dl);
			ft_printf("\033[33mNew pid client : \033[33;04m%d\033[00m\n", (int)(x->si_pid));
		}
		ft_printf("\033[35mSIGUSR2\033[35;02m received - 1\t\t\t\t\ti.signal = %d  (%d)\033[00m\n", g_d.i_signal, g_d.stock_signal);
		stock_li = dl_find_pid(g_d.client_connected, (int)(x->si_pid));
		if (!stock_li)
		{
			write(2, "\033[31;01mError - Client not found\033[00m\n", 40);
			exit(1);
		}
		stock_li = li_new(0);
		if (!stock_li)
		{
			dl_clear(&g_d.client_connected);
			write(2, "\033[31;01mError - Client not found\033[00m\n", 40);
			exit(1);
		}
		li_add_back(&stock_li, stock_li);
		kill((int)(x->si_pid), 12);
		return ;
	}	
}

/*

Le serveur doit être lancé en premier, puis afficher son PID
ssa = Struct SigAction
ssi = Struct SigInfo

*/
