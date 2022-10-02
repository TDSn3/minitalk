/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:19:08 by tda-silv          #+#    #+#             */
/*   Updated: 2022/10/02 15:34:15 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	dl_clear(t_dl **lst)
{
	t_dl	*copyl;

	copyl = *lst;
	if (!*lst)
		return ;
	while (copyl)
	{
		*lst = copyl->next;
		free(copyl);
		li_clear(&(copyl->next_li));
		copyl = *lst;
	}
	*lst = NULL;
}
