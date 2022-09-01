/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_send_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:19:05 by tda-silv          #+#    #+#             */
/*   Updated: 2022/09/01 12:44:58 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	s_send_signal(char *str, int pid_client)
{
	int	i;

	i = 0;
	while (str[i])
	{
		printf("%c", str[i]);
		if (str[i] == '0')	
			kill(pid_client, 10);
		else if (str[i] == '1')	
			kill(pid_client, 12);
		i++;
	}
	printf("\n");
}
