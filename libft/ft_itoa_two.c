/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 12:15:18 by tda-silv          #+#    #+#             */
/*   Updated: 2022/10/13 16:15:01 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

static void	ft_swap(char *s)
{
	size_t	a;
	size_t	z;
	int		copy;

	a = 0;
	z = ft_strlen(s) - 1;
	while (a < z)
	{
		copy = s[a];
		s[a] = s[z];
		s[z] = copy;
		a++;
		z--;
	}
}

static void	ft_swap_index(char *s, int a)
{
	int	z;
	int		copy;

	z = ft_strlen(s) - 1;
	while (a < z)
	{
		copy = s[a];
		s[a] = s[z];
		s[z] = copy;
		a++;
		z--;
	}
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

static char	*ft_cpy(unsigned int n_size, long int n_copy, char *s)
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

char	*ft_itoa_two(int n)
{
	long int		n_copy;
	unsigned int	n_size;
	int				symbol;
	long int		n2;
	char			*s;
	int				i;

	n_copy = n;
	n_size = 0;
	symbol = 0;
	i = 0;
	if (n == 0)
		n_size = 1;
	if (n < 0)
	{
		n = (n * -1) - 1;
		n_copy = n;
		n2 = n_copy;
		while (n2 > 0)
		{
			n2 /= 2;
			n_size++;
		}
		s = malloc(9);
		if (!s)
			return (NULL);
		while (i < 9)
		{
			s[i] = 0 + '0';
			i++;
		}
		if (!s)
			return (NULL);
		s[8] = 0;
		s[0] = 1 + '0';
		ft_cpy(n_size, n_copy, s + (8 - n_size));
		ft_swap_index(s, (8 - n_size));
		inversion(s);
		return (s);
	}
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
	if (symbol)
		s[0] = '-';
	return (s);
}
