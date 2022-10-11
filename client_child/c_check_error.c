/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_check_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 11:49:58 by tda-silv          #+#    #+#             */
/*   Updated: 2022/10/11 12:57:12 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	c_check_error(int argc, char *argv[])
{
	int	i;
	int	pid_server;

	i = 0;
	if (argc != 3 || !argv[2] || !argv[2][0])
	{
		write(2, "\033[31;01mError - Not a good number of parameters, need two\033[00m\n", 65);
		return (1);
	}
	while (argv[1][i])
	{
		if (argv[1][i] < '0' || argv[1][i] > '9')
			{
				write(2, "\033[31;01mError - The first parameter is not a number\033[00m\n", 59);
				return (1);			
			}
		i++;
	}
	pid_server = ft_atoi(argv[1]);
	if (kill(pid_server, 0) == -1)
	{
		write(2, "\033[31;01mError - Wrong pid server\033[00m\n", 40);
		return (1);
	}
	else
		ft_printf("\033[32;03mConnexion establised with the server - Pid server : \033[32;04m%d\033[00m\n", pid_server);
	return (0);
}
/*

Renvois Error si :
- le client ne reçoit pas 2 arguments ou si le deuxième argument est NULL
- le premier argument ne contient pas que des chiffres
- le pib server n'est pas bon

*/
