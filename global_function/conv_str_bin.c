/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_str_bin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:42:31 by tda-silv          #+#    #+#             */
/*   Updated: 2022/10/11 12:43:10 by tda-silv         ###   ########.fr       */
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
		str_return = ft_strjoin(&str_return, &str);
		i++;
	}
	str = malloc(9);
	if (!str)
		return (NULL);
	str[8] = 0;
	i = 0;
	while (i < 8)
	{
		str[i] = '0';
		i++;
	}
	str_return = ft_strjoin(&str_return, &str);
	return (str_return);
}
