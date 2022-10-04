/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:37:06 by tda-silv          #+#    #+#             */
/*   Updated: 2022/10/04 16:34:11 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static t_s_data_minitalk	g_d;
static void	handler(int signal, siginfo_t *x, void *y);
void	check_null_li(t_dl *list, int pid);

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
		ft_printf("\033[34mSIGUSR1\033[34;02m received - 0   | i.zero = %d\t\t\ti.signal = %d  (%d)\033[00m\n", g_d.i_zero, g_d.i_signal,g_d.stock_signal);
		stock_li = dl_find_pid(g_d.client_connected, (int)(x->si_pid));
		if (!stock_li)
		{
			write(2, "Error - Client not found\n", 25);
			exit(1);
		}
		li_add_back(&stock_li, li_new(0));
		check_null_li(g_d.client_connected, (int)(x->si_pid));
		kill((int)(x->si_pid), 10);
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
		printf("\033[35mSIGUSR2\033[35;02m received - 1\t\t\t\t\ti.signal = %d  (%d)\033[00m\n", g_d.i_signal, g_d.stock_signal);
		stock_li = dl_find_pid(g_d.client_connected, (int)(x->si_pid));
		if (!stock_li)
		{
			write(2, "Error - Client not found\n", 25);
			exit(1);
		}
		li_add_back(&stock_li, li_new(1));
		kill((int)(x->si_pid), 12);
	}
	(void) x;
	(void) y;
}

void	check_null_li(t_dl *list, int pid)
{
	t_dl	*cpy_dl;
	t_li	*cpy_li;
	int		i_zero;
	int		i_nb;
	int		j;
	char	stock_octet[9];

	i_zero = 0;
	i_nb = 0;
	cpy_dl = list;
	j = 0;
	stock_octet[8] = 0;
	while (cpy_dl)
	{
		cpy_li = cpy_dl->next_li;



		if (cpy_dl->content == pid)
		{
			if (cpy_li->content == -1 && cpy_li->next)
				cpy_li = cpy_li->next;
			else
				return ;
			
			
			
			while (cpy_li)
			{
				if (cpy_li->content == 0)
					i_zero++;
	
	

				if (i_zero == 8)
				{
					while (cpy_li->prev->content != -1)
						cpy_li = cpy_li->prev;
	
	
	
					while (cpy_li)
					{
						if (j == 8)
						{
							j = 0;
							printf("\033[00;02m(%s)\033[00m", stock_octet);
							printf("%c ", conv_oct_int(stock_octet));
						}
						stock_octet[j] = cpy_li->content + '0';
						cpy_li = cpy_li->next;
						j++;
					}
					printf("\n");
					cpy_dl->content = -1;
					cpy_dl->next_li->content = -2;
					return ;
				}
	
	
	
				i_nb++;
				if (i_nb % 8 == 0)
					i_zero = 0;
				cpy_li = cpy_li->next;
			}
		}


		i_zero = 0;
		cpy_dl = cpy_dl->next;
	}
}
/*

Le serveur doit être lancé en premier, puis afficher son PID
ssa = Struct SigAction
ssi = Struct SigInfo

*/
