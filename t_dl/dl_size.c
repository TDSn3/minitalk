/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:59:36 by tda-silv          #+#    #+#             */
/*   Updated: 2022/10/02 15:57:44 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	dl_size(t_dl *lst)
{
	t_dl	*nextl;
	size_t	i;

	i = 0;
	nextl = lst;
	if (!lst)
		return (0);
	while (nextl)
	{
		nextl = nextl->next;
		i++;
	}
	return (i);
}
