/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:37:06 by tda-silv          #+#    #+#             */
/*   Updated: 2022/09/30 15:14:32 by tda-silv         ###   ########.fr       */
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
	while (1)
	{
		sigaction(SIGUSR1, &ssa_a, 0);
		sigaction(SIGUSR2, &ssa_a, 0);
	}
	return (0);
}

static void	handler(int signal, siginfo_t *x, void *y)
{
	if (signal == 10)
	{
		if (g_d.i_signal % 8 == 0)
			g_d.i_zero = 0;
		g_d.stock_signal = 1;
		g_d.i_signal += 1;
		g_d.i_zero += 1;
		if (!li_find_pid(g_d.client_connected, (int)(x->si_pid)))
		{
			li_add_back(&g_d.client_connected, li_new((int)(x->si_pid)));
			ft_printf("New pid clien : %d\n", (int)(x->si_pid));
		}
		kill((int)(x->si_pid), 10);
		ft_printf("\033[34mSIGUSR1\033[34;02m received - 0   | i.zero = %d\t\t\ti.signal = %d  (%d)\033[00m\n", g_d.i_zero, g_d.i_signal,g_d.stock_signal);
	}
	else if (signal == 12)
	{
		g_d.stock_signal = 2;
		g_d.i_signal += 1;
		kill((int)(x->si_pid), 12);
		printf("\033[35mSIGUSR2\033[35;02m received - 1\t\t\t\t\ti.signal = %d  (%d)\033[00m\n", g_d.i_signal, g_d.stock_signal);
	}
	(void) x;
	(void) y;
}
/*

Le serveur doit être lancé en premier, puis afficher son PID
ssa = Struct SigAction
ssi = Struct SigInfo

*/
