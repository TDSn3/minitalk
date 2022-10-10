/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_str_bin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:42:31 by tda-silv          #+#    #+#             */
/*   Updated: 2022/10/10 14:13:32 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

char *conv_str_bin(char *argv)
{
	int		i;
	char	*str;
	char	*str_return;

	i = 0;
	str = NULL;
	str_return = NULL;
	i = 0;
	while (argv[i])
	{
		str = ft_itoa_two(argv[i]);
		if (argv[i] > 0)
			str = add_zero(&str);
		str_return = ft_strjoin(str_return, str);
		i++;
	}
	str_return = ft_strjoin(str_return, "00000000");
	return (str_return);
}
