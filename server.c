/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:37:06 by tda-silv          #+#    #+#             */
/*   Updated: 2022/08/31 17:43:46 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	handler(int signal);

int	main(void)
{
	int					pid;
	struct sigaction	start_signal;
	
	start_signal.sa_handler = &handler;
	start_signal.sa_flags = 0;
	sigemptyset(&start_signal.sa_mask);
	pid = getpid();
	printf("Pid server : %d\n", pid);
	
	while (1)
	{
		sigaction(SIGUSR1, &start_signal, 0);
	}
	
	return (0);
}

/*

Le serveur doit être lancé en premier, puis afficher son PID

*/

void	handler(int signal)
{
	printf("OK the signal %d\n", signal);
}
