/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_send_str_signal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:05:48 by tda-silv          #+#    #+#             */
/*   Updated: 2022/10/05 15:37:01 by tda-silv         ###   ########.fr       */
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
	while (str[i])
	{
		if (str[i] == '0')	
		{
			kill(g_d->pid_server, 10);
			sigaction(SIGUSR1, &ssa_a, 0);
			if (sleep(2) == 0)
			{
				kill(g_d->pid_server, 10);
				sigaction(SIGUSR1, &ssa_a, 0);
				if (sleep(2) == 0)
				{
					write(2, "Error - One bit lost\n", 22);
					exit(1);
				}
			}
		}
		else if (str[i] == '1')	
		{
			kill(g_d->pid_server, 12);
			sigaction(SIGUSR2, &ssa_a, 0);
			if (sleep(2) == 0)
			{
				kill(g_d->pid_server, 12);
				sigaction(SIGUSR2, &ssa_a, 0);
				if (sleep(2) == 0)
				{
					write(2, "Error - One bit lost\n", 22);
					exit(1);
				}
			}
		}
		i++;
		usleep(50000); // 100000 pour valgrind sinon 500
	}
}

static void	handler(int signal, siginfo_t *x, void *y)
{
	if (signal == 10)
	{
		ft_printf("\033[34mSIGUSR1\033[34;02m received - 0\033[00m\n");
	}
	else if (signal == 12)
	{
		printf("\033[35mSIGUSR2\033[35;02m received - 1\033[00m\n");
	}
	(void) x;
	(void) y;
}
