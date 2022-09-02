/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_clear_one.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 08:58:51 by tda-silv          #+#    #+#             */
/*   Updated: 2022/09/02 12:23:56 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	li_clear_one(t_li **li, int content)
{
	t_li	*li_cpy;
	int		li_size_stock;

	li_size_stock = li_size(*li);
	li_cpy = *li;
	if (li_size_stock == 1)
	{
		free(*li);
		*li = NULL;
		return ;
	}	
	while (li_cpy && li_cpy->content != content)
		li_cpy = li_cpy->next;
	if (li_cpy->content == content)
	{
		if (li_cpy->prev)
			li_cpy->prev->next = li_cpy->next;
		if (li_cpy->next)
		{
			li_cpy->next->prev = li_cpy->prev;
			if (li_cpy == *li)
				*li = li_cpy->next;
		}
		free(li_cpy);
	}
}
