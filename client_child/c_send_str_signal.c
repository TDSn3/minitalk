/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_send_str_signal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:05:48 by tda-silv          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/10/06 17:16:41 by tda-silv         ###   ########.fr       */
=======
/*   Updated: 2022/10/05 15:37:01 by tda-silv         ###   ########.fr       */
>>>>>>> 8edb5e6eb958658a5ca95e8fa4db97b773fcfb2f
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
<<<<<<< HEAD
			if (sleep(10) == 0)
			{
				kill(g_d->pid_server, 10);
=======
			sigaction(SIGUSR1, &ssa_a, 0);
			if (sleep(2) == 0)
			{
				kill(g_d->pid_server, 10);
				sigaction(SIGUSR1, &ssa_a, 0);
>>>>>>> 8edb5e6eb958658a5ca95e8fa4db97b773fcfb2f
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
<<<<<<< HEAD
			if (sleep(10) == 0)
			{
				kill(g_d->pid_server, 12);
=======
			sigaction(SIGUSR2, &ssa_a, 0);
			if (sleep(2) == 0)
			{
				kill(g_d->pid_server, 12);
				sigaction(SIGUSR2, &ssa_a, 0);
>>>>>>> 8edb5e6eb958658a5ca95e8fa4db97b773fcfb2f
				if (sleep(2) == 0)
				{
					write(2, "Error - One bit lost\n", 22);
					exit(1);
				}
			}
		}
		i++;
<<<<<<< HEAD
//		usleep(500); // 100000 pour valgrind sinon 500
=======
		usleep(50000); // 100000 pour valgrind sinon 500
>>>>>>> 8edb5e6eb958658a5ca95e8fa4db97b773fcfb2f
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
