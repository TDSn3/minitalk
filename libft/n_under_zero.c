/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_under_zero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 15:31:48 by tda-silv          #+#    #+#             */
/*   Updated: 2022/10/15 16:46:24 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*build_negative_oct(void);
static void	inversion(char *s);

char	*n_under_zero(int n, unsigned int *n_size)
{
	long int		n_copy;
	long int		n2;
	char			*s;

	n = (n * -1) - 1;
	n_copy = n;
	n2 = n_copy;
	while (n2 > 0)
	{
		n2 /= 2;
		*n_size += 1;
	}
	s = build_negative_oct();
	if (!s)
		return (NULL);
	ft_cpy(*n_size, n_copy, s + (8 - *n_size));
	ft_swap_index(s, (8 - *n_size));
	inversion(s);
	return (s);
}

static char	*build_negative_oct(void)
{
	int		i;
	char	*s;

	i = 0;
	s = malloc(9);
	if (!s)
		return (NULL);
	while (i < 9)
	{
		s[i] = 0 + '0';
		i++;
	}
	s[8] = 0;
	s[0] = 1 + '0';
	return (s);
}

static void	inversion(char *s)
{
	int	a;

	a = 1;
	while (s[a])
	{
		if (s[a] == '0')
			s[a] = '1';
		else
			s[a] = '0';
		a++;
	}	
}
