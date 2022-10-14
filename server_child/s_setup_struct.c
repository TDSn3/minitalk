/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_setup_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 10:04:14 by tda-silv          #+#    #+#             */
/*   Updated: 2022/10/14 16:55:46 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	s_setup_struct(t_s_data_minitalk *g_d)
{
	g_d->pid_server = 0;
	g_d->pid_client = 0;
	g_d->client_connected = NULL;
}

/*

Initialise la structure

*/
