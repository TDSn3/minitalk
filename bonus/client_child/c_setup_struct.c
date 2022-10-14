/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_setup_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 10:04:14 by tda-silv          #+#    #+#             */
/*   Updated: 2022/10/10 16:59:32 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	c_setup_struct(t_c_data_minitalk *g_d)
{
	g_d->pid_server = 0;
	g_d->pid_client = 0;
	g_d->i_signal = 0;
	g_d->stock_signal = 0;
}

/*

Initialise la structure

*/
