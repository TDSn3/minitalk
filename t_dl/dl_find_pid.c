/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_find_pid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:22:19 by tda-silv          #+#    #+#             */
/*   Updated: 2022/10/02 18:15:02 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_li *dl_find_pid(t_dl *client_connected, int pid)
{
	t_dl	*nextl;
	size_t	i;

	i = 0;
	nextl = client_connected;
	if (!client_connected)
		return (NULL);
	while (nextl)
	{
		if (nextl->content == pid)
			return (nextl->next_li);
		nextl = nextl->next;
		i++;
	}
	return (NULL);
}
