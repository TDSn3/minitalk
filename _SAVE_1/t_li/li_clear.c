/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:19:08 by tda-silv          #+#    #+#             */
/*   Updated: 2022/09/02 12:24:10 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	li_clear(t_li **lst)
{
	t_li	*copyl;

	copyl = *lst;
	if (!*lst)
		return ;
	while (copyl)
	{
		*lst = copyl->next;
		free(copyl);
		copyl = *lst;
	}
	*lst = NULL;
}
