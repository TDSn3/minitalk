/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_size_bin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 12:01:21 by tda-silv          #+#    #+#             */
/*   Updated: 2022/10/10 14:13:46 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	conv_size_bin(char *str, int pid, size_t size_pid_client)
{	
	size_t	i;
	int		j;
	int		x;
	char	*stock_bin;
	
(void)str;
	
	i = 0;
	j = 0;
	x = 0;
	while (i < size_pid_client)
	{
		stock_bin = ft_itoa_two((pid % 10) + '0');
		stock_bin = add_zero(&stock_bin);

		while (j < 8)
		{
			str[x] = stock_bin[j];
			x++;
			j++;
		}
		j = 0;
		free(stock_bin);
		pid /= 10;
		i++;
	}
	while (j < 8)
	{
		str[x] = '0';
		x++;
		j++;
	}
	str[x] = 0;
} 
/*

Calcul la taille du pid
Passez 0 pour le paramètre size_pid

*/