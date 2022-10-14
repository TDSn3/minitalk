/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_conv_str_bin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 10:44:35 by tda-silv          #+#    #+#             */
/*   Updated: 2022/09/02 14:20:08 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	c_conv_str_bin(char *argv[], int pid_server)
{
	int		i;
	char	*str;

	i = 0;
	while (argv[2][i])
	{
		str = ft_itoa_two(argv[2][i]);
		str = add_zero(&str);
		c_send_signal(str, pid_server);
		free(str);
		i++;
	}	
}

/*

Converti une string composé de caractères en son équivalent binaire

*/
