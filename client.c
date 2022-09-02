/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:36:59 by tda-silv          #+#    #+#             */
/*   Updated: 2022/09/02 12:53:05 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	handler(int signal);

int	main(int argc, char *argv[])
{
	int		pid_client;
	char	*str_pid_client;
	int		pid_server;
	size_t	size_pid_client;
	char	*size_pid_clien_bin;

	size_pid_client = 0;
	pid_client = getpid();
	printf("\033[33mPid client : \033[33;04m%d\033[00m\n", pid_client);

	if (c_check_error(argc, argv))
		return (1);
	pid_server = ft_atoi(argv[1]);

	{
		find_size_pid(pid_client, &size_pid_client);
		printf("\033[32;02mSize of pid is %zu\033[00m\n", size_pid_client);
		(void) str_pid_client;
		
		size_pid_clien_bin = malloc((8 * size_pid_client) + 9); // alloue 8 bits par caractere plus 8 pour le 8*0 + 1 pour le NULL
		conv_size_bin(size_pid_clien_bin, pid_client, size_pid_client);

		{
			int	i;
			struct sigaction	start_signal;
			
			start_signal.sa_handler = &handler;
			start_signal.sa_flags = 0;
			sigemptyset(&start_signal.sa_mask);

			i = 0;
			while (size_pid_clien_bin[i])
			{
				if (size_pid_clien_bin[i] == '0')	
					kill(pid_server, 10);
				else if (size_pid_clien_bin[i] == '1')	
					kill(pid_server, 12);
				i++;
				usleep(100000); // 100000 pour valgrind sinon 500
				sigaction(SIGUSR1, &start_signal, 0);
				sigaction(SIGUSR2, &start_signal, 0);
			}
		}

		free(size_pid_clien_bin);
//		str_pid_client = ft_itoa(pid_client);
//		printf("PID CLIENT = %s", str_pid_client);
//		c_conv_str_bin(&str_pid_client, pid_server);
	}

//	c_conv_str_bin(argv, pid_server);
	return (0);
}

/*

Le client prend deux paramètres :
- Le PID du serveur
- Une chaîne de caractères à transmettre

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
