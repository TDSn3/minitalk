/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:36:59 by tda-silv          #+#    #+#             */
/*   Updated: 2022/08/31 16:59:43 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	conv_str_bin(char *argv[]);
char	*add_zero(char **str);

int	main(int argc, char *argv[])
{
	int	pid_server;
		
	if (c_check_error(argc, argv))
		return (1);
	pid_server = ft_atoi(argv[1]);
	
	conv_str_bin(argv);
	
	kill(pid_server, 10);
	return (0);
}

/*

Le client prend deux paramètres :
- Le PID du serveur
- Une chaîne de caractères à transmettre

*/

void	conv_str_bin(char *argv[])
{
	int		i;
	char	*str;

	i = 0;
	while (argv[2][i])
	{
		str = ft_itoa(argv[2][i]);
		str = add_zero(&str);
		printf("%s\n", str);
		free(str);
		i++;
	}	
}

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