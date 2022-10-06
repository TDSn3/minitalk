/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:36:59 by tda-silv          #+#    #+#             */
/*   Updated: 2022/10/06 17:19:21 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static t_c_data_minitalk	g_d;

int	main(int argc, char *argv[])
{
	char				*str_bin;
	
	c_setup_struct(&g_d);
	g_d.pid_client = getpid();
	ft_printf("\033[33mPid client : \033[33;04m%d\033[00m\n", g_d.pid_client);
	if (c_check_error(argc, argv))
		return (1);
	g_d.pid_server = ft_atoi(argv[1]);
	str_bin = conv_str_bin(argv[2]);
	c_send_str_signal(&g_d, str_bin);
	return (0);
}

/*

Le client prend deux paramètres :
- Le PID du serveur
- Une chaîne de caractères à transmettre

*/
