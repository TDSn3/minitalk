/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_zero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:02:10 by tda-silv          #+#    #+#             */
/*   Updated: 2022/10/13 16:21:13 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

char	*add_zero(char **str)
{
	int		size_str;
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	size_str = ft_strlen(*str);
	if (size_str < 8)
	{
		new_str = malloc(9);
		if (!new_str)
		{
			write(2, "\033[31;01mError - Malloc failled\033[00m\n", 38);
			free(*str);
			exit (1);
		}
		while (i < 8 - size_str)
		{
			new_str[i] = '0';
			i++; 
		}
		while (i < 8)
		{
			new_str[i] = (*str)[j];
			i++;
			j++;
		}
		new_str[8] = 0;
		free(*str);
		return (new_str);
	}
	return (NULL);
}