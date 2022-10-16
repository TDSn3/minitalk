/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_check_null_li.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:00:21 by tda-silv          #+#    #+#             */
/*   Updated: 2022/10/16 00:59:30 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static int	search_zero_li(t_dl **list, int pid, t_li *cpy_li);
static int	print_li(t_dl **list, int pid, t_li *cpy_li);

int	s_check_null_li(t_dl **list, int pid)
{
	t_dl	*cpy_dl;
	t_li	*cpy_li;

	cpy_dl = *list;
	while (cpy_dl)
	{
		if (!cpy_dl->next_li)
			return (0);
		cpy_li = cpy_dl->next_li;
		if (cpy_dl->content == pid)
			if (search_zero_li(list, pid, cpy_li))
				return (1);
		cpy_dl = cpy_dl->next;
	}
	return (0);
}

static int	search_zero_li(t_dl **list, int pid, t_li *cpy_li)
{
	int		i_zero;
	int		i_nb;

	i_zero = 0;
	i_nb = 0;
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
			return (print_li(list, pid, cpy_li));
		cpy_li = cpy_li->next;
	}
	return (0);
}

static int	print_li(t_dl **list, int pid, t_li *cpy_li)
{
	int		i;
	char	stock_octet[9];

	i = 0;
	stock_octet[8] = 0;
	while (cpy_li->prev->content != -1)
		cpy_li = cpy_li->prev;
	while (cpy_li)
	{
		if (i == 8)
		{
			i = 0;
			ft_printf("%c", conv_oct_int(stock_octet));
		}
		stock_octet[i] = cpy_li->content + '0';
		cpy_li = cpy_li->next;
		i++;
	}
	ft_printf("\n");
	dl_clear_one(list, pid);
	return (1);
}
