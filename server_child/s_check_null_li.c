/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_check_null_li.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:00:21 by tda-silv          #+#    #+#             */
/*   Updated: 2022/10/11 15:01:44 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	s_check_null_li(t_dl **list, int pid)
{
	t_dl	*cpy_dl;
	t_li	*cpy_li;
	int		i_zero;
	int		i_nb;
	int		j;
	char	stock_octet[9];

	i_zero = 0;
	i_nb = 0;
	cpy_dl = *list;
	j = 0;
	stock_octet[8] = 0;
	while (cpy_dl)
	{
		if (!cpy_dl->next_li)
			return (0);
		cpy_li = cpy_dl->next_li;
		if (cpy_dl->content == pid)
		{		
			if (cpy_li->content == -1 && cpy_li->next)
				cpy_li = cpy_li->next;
			else
				return (0);
			while (cpy_li)
			{
				if (i_nb % 8 == 0)
					i_zero = 0;	
				if (cpy_li->content == 0)
					i_zero++;
				i_nb++;
				if (i_zero == 8)
				{
					ft_printf("\n");
					while (cpy_li->prev->content != -1)
						cpy_li = cpy_li->prev;
					while (cpy_li)
					{
						if (j == 8)
						{
							j = 0;
							ft_printf("%c", conv_oct_int(stock_octet));
						}
						stock_octet[j] = cpy_li->content + '0';
						cpy_li = cpy_li->next;
						j++;
					}
					ft_printf("\n");
					dl_clear_one(list, pid);
					return (1);
				}
				cpy_li = cpy_li->next;
			}
		}
		i_nb = 0;
		i_zero = 0;
		cpy_dl = cpy_dl->next;
	}
	return (0);
}
