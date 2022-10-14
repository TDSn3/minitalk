/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_find_pid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:22:19 by tda-silv          #+#    #+#             */
/*   Updated: 2022/10/14 19:11:23 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	li_find_pid(t_li *client_connected, int pid)
{
	t_li	*nextl;
	size_t	i;

	i = 0;
	nextl = client_connected;
	if (!client_connected)
		return (0);
	while (nextl)
	{
		if (nextl->content == pid)
			return (pid);
		nextl = nextl->next;
		i++;
	}
	return (0);
}
