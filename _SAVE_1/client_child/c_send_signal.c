/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_send_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:19:05 by tda-silv          #+#    #+#             */
/*   Updated: 2022/09/01 11:30:25 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	c_send_signal(char *str, int pid_server)
{
	int	i;

	i = 0;
	while (str[i])
	{
		printf("%c", str[i]);
		if (str[i] == '0')	
			kill(pid_server, 10);
		else if (str[i] == '1')	
			kill(pid_server, 12);
		i++;
	}
	printf("\n");
}
