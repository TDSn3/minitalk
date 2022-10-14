/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_size_pid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 12:01:21 by tda-silv          #+#    #+#             */
/*   Updated: 2022/09/01 14:40:30 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	find_size_pid(int n, size_t *size_pid)
{	
	if (n > 9)
	{
		*size_pid += 1;
		find_size_pid(n / 10, size_pid);
	}
	else if (n < 9)
		*size_pid += 1;
} 
/*

Calcul la taille du pid
Passez 0 pour le paramètre size_pid

*/