/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 10:04:14 by tda-silv          #+#    #+#             */
/*   Updated: 2022/09/02 12:41:53 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	stetup_struct(t_data *g_d)
{
	g_d->i_signal = 0;
	g_d->stock_signal_rec = 0;
	g_d->i_zero = 0;
	g_d->on_off = 0;
	g_d->list_bit = NULL;
}
