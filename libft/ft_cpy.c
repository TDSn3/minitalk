/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 15:52:58 by tda-silv          #+#    #+#             */
/*   Updated: 2022/10/15 15:53:24 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_cpy(unsigned int n_size, long int n_copy, char *s)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 1;
	while (i < n_size)
	{
		s[i] = ((n_copy / j) % 2) + 48;
		j *= 2;
		i++;
	}
	s[i] = 0;
	return (s);
}
