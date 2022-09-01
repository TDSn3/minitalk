/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:37:06 by tda-silv          #+#    #+#             */
/*   Updated: 2022/09/01 17:59:36 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	handler(int signal);

int	main(void)
{
	int					i;
	int					nb_of_zero;
	int					pid_client;
	struct sigaction	start_signal;
	
	start_signal.sa_handler = &handler;
	start_signal.sa_flags = 0;
	sigemptyset(&start_signal.sa_mask);
	
	i = 0;
	nb_of_zero = 0;
	pid_client = getpid();
	printf("Pid server : %d\n", pid_client);
	
	while (1)
	{
		sigaction(SIGUSR1, &start_signal, 0);
		sigaction(SIGUSR2, &start_signal, 0);

		while (1)
		{
			if (i % 8 == 0 && )
				>IIIIIICCCCCCCCCCCCCIIIIIIIIIIIIIIIIII< comment stcoker le signal recus
		} 
		
	}
	
	return (0);
}

/*

Le serveur doit être lancé en premier, puis afficher son PID

*/

static void	handler(int signal)
{
	if (signal == 10)
	{
		printf("SIGUSR1 received - 0\n");
	}
	else if (signal == 12)
	{
		printf("SIGUSR2 received - 1\n");
	}
}
