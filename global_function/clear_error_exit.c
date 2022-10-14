/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_error_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:44:47 by tda-silv          #+#    #+#             */
/*   Updated: 2022/10/14 19:10:07 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	clear_error_exit(t_dl **client_connected, int choice)
{
	if (choice == 1)
	{
		dl_clear(client_connected);
		write(2, "\033[31;01mError - Malloc failled\033[00m\n", 38);
	}
	if (choice == 2)
	{
		dl_clear(client_connected);
		write(2, "\033[31;01mError - Client not found\033[00m\n", 40);
	}
	return (1);
}
