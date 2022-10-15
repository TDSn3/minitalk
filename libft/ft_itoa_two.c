/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 12:15:18 by tda-silv          #+#    #+#             */
/*   Updated: 2022/10/15 16:18:01 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_two(int n)
{
	long int		n_copy;
	unsigned int	n_size;
	long int		n2;
	char			*s;

	n_copy = n;
	n_size = 0;
	if (n == 0)
		n_size = 1;
	if (n < 0)
		return (n_under_zero(n, &n_size));
	n2 = n_copy;
	while (n2 > 0)
	{
		n2 /= 2;
		n_size++;
	}
	s = malloc(n_size + 1);
	if (!s)
		return (NULL);
	ft_swap(ft_cpy(n_size, n_copy, s));
	return (s);
}
