/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:37:06 by tda-silv          #+#    #+#             */
/*   Updated: 2022/10/02 19:33:42 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static t_s_data_minitalk	g_d;
static void	handler(int signal, siginfo_t *x, void *y);
void	check_null_li(t_dl *list);

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
	t_li	*stock_li;
	
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
			ft_printf("New pid clien : %d\n", (int)(x->si_pid));
		}
		kill((int)(x->si_pid), 10);
		ft_printf("\033[34mSIGUSR1\033[34;02m received - 0   | i.zero = %d\t\t\ti.signal = %d  (%d)\033[00m\n", g_d.i_zero, g_d.i_signal,g_d.stock_signal);
		stock_li = dl_find_pid(g_d.client_connected, (int)(x->si_pid));
		if (!stock_li)
		{
			write(2, "Error - Client not found\n", 25);
			exit(1);
		}
		li_add_back(&stock_li, li_new(0));
		check_null_li(g_d.client_connected);
	}
	else if (signal == 12)
	{
		g_d.stock_signal = 2;
		g_d.i_signal += 1;
		if (!dl_find_pid(g_d.client_connected, (int)(x->si_pid)))
		{
			dl_add_back(&g_d.client_connected, dl_new((int)(x->si_pid)));
			ft_printf("New pid clien : %d\n", (int)(x->si_pid));
		}
		kill((int)(x->si_pid), 12);
		printf("\033[35mSIGUSR2\033[35;02m received - 1\t\t\t\t\ti.signal = %d  (%d)\033[00m\n", g_d.i_signal, g_d.stock_signal);
		stock_li = dl_find_pid(g_d.client_connected, (int)(x->si_pid));
		if (!stock_li)
		{
			write(2, "Error - Client not found\n", 25);
			exit(1);
		}
		li_add_back(&stock_li, li_new(1));
	}
	(void) x;
	(void) y;
}

void	check_null_li(t_dl *list)
{
	t_dl	*cpy_dl;
	t_li	*cpy_li;
	int		i;
	int		k;

	i = 0;
	k = 0;
	cpy_dl = list;
	while (cpy_dl)
	{
		cpy_li = cpy_dl->next_li;
		while (cpy_li)
		{
			if (cpy_li->content == 0)
				i++;
			else
				i = 0;
			if (i == 8 && k % 8 == 0)
			{
				while (cpy_li->prev)
				{
					cpy_li = cpy_li->prev;
				}
				if (cpy_li->content == -1)
					cpy_li = cpy_li->next;

				int		j;
				char	stock_octet[9];
					
				stock_octet[8] = 0;
				j = 0;
				while (cpy_li)
				{
					if (j == 8)
					{
						j = 0;
						printf("\033[00;02m(%s)\033[00m", stock_octet);
						printf("%c", conv_oct_int(stock_octet));
					}
					stock_octet[j] = cpy_li->content + '0';
					cpy_li = cpy_li->next;
					j++;
				}
				printf("\n");
				dl_clear_one(&list, cpy_dl->content);
				return ;
			}
			if (k % 8 == 0)
				k = 0;
			cpy_li = cpy_li->next;
			k++;
		}
		i = 0;
		cpy_dl = cpy_dl->next;
	}
}
/*

Le serveur doit être lancé en premier, puis afficher son PID
ssa = Struct SigAction
ssi = Struct SigInfo

*/
