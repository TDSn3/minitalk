/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_str_bin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:42:31 by tda-silv          #+#    #+#             */
/*   Updated: 2022/10/13 16:23:50 by tda-silv         ###   ########.fr       */
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
		if (!str)
		{
			write(2, "\033[31;01mError - Malloc failled\033[00m\n", 38);
			exit (1);
		}
		if (argv[i] > 0)
		str = add_zero(&str);
		str_return = ft_strjoin(&str_return, &str);
		i++;
	}
	str = malloc(9);
	if (!str)
	{
		free(str_return);
		write(2, "\033[31;01mError - Malloc failled\033[00m\n", 38);
		exit (1);
	}
	str[8] = 0;
	i = 0;
	while (i < 8)
	{
		str[i] = '0';
		i++;
	}
	str_return = ft_strjoin(&str_return, &str);
	if (!str_return)
	{
		free(str);
		write(2, "\033[31;01mError - Malloc failled\033[00m\n", 38);
		exit (1);
	}
	return (str_return);
}
