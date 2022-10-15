/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ten.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 12:15:18 by tda-silv          #+#    #+#             */
/*   Updated: 2022/10/15 16:20:17 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_zero_or_neg(long int *n_copy, unsigned int *n_size, int *symbol)
{
	*n_size = 1;
	if (*n_copy < 0)
	{
		*n_copy *= -1;
		*symbol = 1;
	}
}

char	*ft_itoa_ten(int n)
{
	long int		n_copy;
	unsigned int	n_size;
	int				symbol;
	long int		n2;
	char			*s;

	n_copy = n;
	n_size = 0;
	symbol = 0;
	if (n <= 0)
		ft_zero_or_neg(&n_copy, &n_size, &symbol);
	n2 = n_copy;
	while (n2 > 0)
	{
		n2 /= 10;
		n_size++;
	}
	s = malloc(n_size + 1);
	if (!s)
		return (NULL);
	ft_swap(ft_cpy(n_size, n_copy, s));
	if (symbol)
		s[0] = '-';
	return (s);
}
/*
#include <stdio.h>

int main(void)
{
    char    *s = ft_itoa(4); // -2147483648
    printf("\ns:%s\n\n", s);
    free(s);
    return (0);
}
*/
