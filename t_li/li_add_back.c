/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_add_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:18:44 by tda-silv          #+#    #+#             */
/*   Updated: 2022/09/24 12:55:55 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	li_add_back(t_li **lst, t_li *new)
{
	t_li	*copyl;

	if (!new)
		return (1);
	if (lst)
	{
		if (!*lst)
			*lst = new;
		else
		{
			copyl = li_last(*lst);
			copyl->next = new;
			copyl->next->prev = copyl;
		}
	}
	return (0);
}
