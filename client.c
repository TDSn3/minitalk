/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:36:59 by tda-silv          #+#    #+#             */
/*   Updated: 2022/09/30 14:38:54 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static t_c_data_minitalk	g_d;
static void	handler(int signal, siginfo_t *x, void *y);

int	main(int argc, char *argv[])
{
	struct sigaction	ssa_a;
	char				*str_bin;
	
	c_setup_struct(&g_d);
	g_d.pid_client = getpid();
	ft_printf("\033[33mPid client : \033[33;04m%d\033[00m\n", g_d.pid_client);
	if (c_check_error(argc, argv))
		return (1);
	g_d.pid_server = ft_atoi(argv[1]);
	ssa_a.sa_sigaction = &handler;
	ssa_a.sa_flags = SA_SIGINFO;
	sigemptyset(&ssa_a.sa_mask);
	str_bin = conv_str_bin(argv[2]);
	c_send_str_signal(&g_d, str_bin);
	return (0);
}

static void	handler(int signal, siginfo_t *x, void *y)
{
	if (signal == 10)
	{
		ft_printf("SIGUSR1 received - 0\n");
	}
	else if (signal == 12)
	{
		ft_printf("SIGUSR2 received - 1\n");
	}
	(void) x;
	(void) y;
}

/*

Le client prend deux paramètres :
- Le PID du serveur
- Une chaîne de caractères à transmettre

*/
