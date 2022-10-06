/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_send_str_signal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:05:48 by tda-silv          #+#    #+#             */
/*   Updated: 2022/10/06 17:16:41 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	handler(int signal, siginfo_t *x, void *y);

void c_send_str_signal(t_c_data_minitalk *g_d, char *str)
{
	int i;
	struct sigaction	ssa_a;

	i = 0;
	ssa_a.sa_sigaction = &handler;
	ssa_a.sa_flags = SA_SIGINFO;
	sigemptyset(&ssa_a.sa_mask);
	sigaction(SIGUSR1, &ssa_a, 0);
	sigaction(SIGUSR2, &ssa_a, 0);
	while (str[i])
	{
		if (str[i] == '0')	
		{
			ft_printf("\033[34;02mSIGUSR1\033[34;02m sended - 0\033[00m ");
			kill(g_d->pid_server, 10);
			if (sleep(10) == 0)
			{
				kill(g_d->pid_server, 10);
				if (sleep(2) == 0)
				{
					write(2, "Error - One bit lost\n", 22);
					exit(1);
				}
			}
		}
		else
		{
			ft_printf("\033[35;02mSIGUSR2\033[35;02m sended - 1\033[00m ");
			kill(g_d->pid_server, 12);
			if (sleep(10) == 0)
			{
				kill(g_d->pid_server, 12);
				if (sleep(2) == 0)
				{
					write(2, "Error - One bit lost\n", 22);
					exit(1);
				}
			}
		}
		i++;
//		usleep(500); // 100000 pour valgrind sinon 500
	}
}

static void	handler(int signal, siginfo_t *x, void *y)
{
	if (signal == 10)
	{
		ft_printf("\033[34m  SIGUSR1\033[34;02m received - 0\033[00m\n");
	}
	else if (signal == 12)
	{
		printf("\033[35m  SIGUSR2\033[35;02m received - 1\033[00m\n");
	}
	(void) x;
	(void) y;
}
