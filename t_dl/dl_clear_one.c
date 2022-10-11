/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_clear_one.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 08:58:51 by tda-silv          #+#    #+#             */
/*   Updated: 2022/10/11 12:08:52 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	dl_clear_one(t_dl **dl, int content)
{
	t_dl	*dl_cpy;
	int		dl_size_stock;

	dl_size_stock = dl_size(*dl);
	dl_cpy = *dl;
	if (dl_size_stock == 1)
	{
		dl_clear(dl);
		return ;
	}	
	while (dl_cpy && dl_cpy->content != content)
		dl_cpy = dl_cpy->next;
	if (dl_cpy->content == content)
	{
		if (dl_cpy->prev)
			dl_cpy->prev->next = dl_cpy->next;
		if (dl_cpy->next)
		{
			dl_cpy->next->prev = dl_cpy->prev;
			if (dl_cpy == *dl)
				*dl = dl_cpy->next;
		}
		li_clear(&dl_cpy->next_li);
		free(dl_cpy);
	}
}
