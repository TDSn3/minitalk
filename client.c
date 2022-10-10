/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:36:59 by tda-silv          #+#    #+#             */
/*   Updated: 2022/10/10 17:15:36 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char *argv[])
{
	char	*str_bin;
	int		pid_client;
	int		pid_server;
	
	pid_client = getpid();
	ft_printf("\033[33mPid client : \033[33;04m%d\033[00m\n", pid_client);
	if (c_check_error(argc, argv))
		return (1);
	pid_server = ft_atoi(argv[1]);
	str_bin = conv_str_bin(argv[2]);
	c_send_str_signal(str_bin, pid_client, pid_server);
	return (0);
}

/*

Le client prend deux paramètres :
- Le PID du serveur
- Une chaîne de caractères à transmettre

*/
