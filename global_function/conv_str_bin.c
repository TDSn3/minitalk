/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_str_bin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:42:31 by tda-silv          #+#    #+#             */
/*   Updated: 2022/10/04 17:23:46 by tda-silv         ###   ########.fr       */
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



	printf("\n1\n");
	while (argv[i])
	{
		printf("%d ", argv[i]);
		i++;
	}
	printf("\n");
	i = 0;

	printf("\n2\n");
	while (argv[i])
	{
		write(1, &argv[i], 1);
		printf("\n%s\n", ft_itoa_two(argv[i]));
		i++;
	}
	printf("\n");
	i = 0;



	
	while (argv[i])
	{
		str = ft_itoa_two(argv[i]);
		str = add_zero(&str);
		str_return = ft_strjoin(str_return, str);
		i++;
	}
	str_return = ft_strjoin(str_return, "00000000");
	ft_printf("str : %s\nstr_bin : %s\n",argv, str_return);
	return (str_return);
}
