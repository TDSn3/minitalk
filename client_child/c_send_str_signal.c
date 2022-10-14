/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_send_str_signal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:05:48 by tda-silv          #+#    #+#             */
/*   Updated: 2022/10/14 19:06:52 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static t_c_data_minitalk	g_d;
static void	handler(int signal, siginfo_t *x, void *y);
static void kill_and_wait_signal_ten(int pid_server);
static void kill_and_wait_signal_twelve(int pid_server);

void c_send_str_signal(char **str, int pid_client, int pid_server)
{
	int i;
	struct sigaction	ssa_a;

	i = 0;
	c_setup_struct(&g_d, str, pid_client, pid_server);
	ssa_a.sa_sigaction = &handler;
	ssa_a.sa_flags = SA_SIGINFO;
	sigemptyset(&ssa_a.sa_mask);
	sigaction(SIGUSR1, &ssa_a, 0);
	sigaction(SIGUSR2, &ssa_a, 0);
	sigaction(SIGINT, &ssa_a, 0);
	while ((*str)[i])
	{
		if ((*str)[i] == '0')	
			kill_and_wait_signal_ten(pid_server);
		else
			kill_and_wait_signal_twelve(pid_server);
		i++;
		g_d.stock_signal = 0;
	}
}

static void	handler(int signal, siginfo_t *x, void *y)
{
	(void) x;
	(void) y;
	if (signal == 2)
	{
		free(*g_d.str_bin);
		exit(0);
	}
	else if (signal == 10)
		g_d.stock_signal = 1;
	else if (signal == 12)
		g_d.stock_signal = 2;
}

static void kill_and_wait_signal_ten(int pid_server)
{
	kill(pid_server, 10);
	if (g_d.stock_signal != 1 && sleep(10) == 0)
	{
		kill(pid_server, 10);
		if (sleep(2) == 0)
		{
			free(*g_d.str_bin);
			write(2, "\nError - One bit lost\n", 22);
			exit(1);
		}
	}
}

static void kill_and_wait_signal_twelve(int pid_server)
{
	kill(pid_server, 12);
	if (g_d.stock_signal != 2 && sleep(10) == 0)
	{
		kill(pid_server, 12);
		if (sleep(2) == 0)
		{
			free(*g_d.str_bin);
			write(2, "\nError - One bit lost\n", 22);
			exit(1);
		}
	}
}