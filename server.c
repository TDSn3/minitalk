/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:37:06 by tda-silv          #+#    #+#             */
/*   Updated: 2022/09/24 13:51:30 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static t_data_minitalk	g_d;
static void	handler(int signal, siginfo_t *x, void *y);

int	main(void)
{
	struct sigaction	ssa_a;
	
	stetup_struct(&g_d);

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

	}
	else if (signal == 12)
	{
		
	}
	(void) x;
	(void) y;
}

/*

Le serveur doit être lancé en premier, puis afficher son PID
ssa = Struct SigAction
ssi = Struct SigInfo

*/
