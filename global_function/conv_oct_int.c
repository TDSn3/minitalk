/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_oct_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 15:20:34 by tda-silv          #+#    #+#             */
/*   Updated: 2022/10/15 21:46:49 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static int	positive_nb(char *str);

int	conv_oct_int(char *str)
{
	int	nb;

	nb = 0;
	if (str[0] == '1')
	{
		nb = 128;
		if (str[1] == '1')
			nb -= 64;
		if (str[2] == '1')
			nb -= 32;
		if (str[3] == '1')
			nb -= 16;
		if (str[4] == '1')
			nb -= 8;
		if (str[5] == '1')
			nb -= 4;
		if (str[6] == '1')
			nb -= 2;
		if (str[7] == '1')
			nb -= 1;
		return ((nb * -1));
	}
	else
		return (positive_nb(str));
}

static int	positive_nb(char *str)
{
	int	nb;

	nb = 0;
	if (str[1] == '1')
		nb += 64;
	if (str[2] == '1')
		nb += 32;
	if (str[3] == '1')
		nb += 16;
	if (str[4] == '1')
		nb += 8;
	if (str[5] == '1')
		nb += 4;
	if (str[6] == '1')
		nb += 2;
	if (str[7] == '1')
		nb += 1;
	return (nb);
}
