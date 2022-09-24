/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_li.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 12:19:00 by tda-silv          #+#    #+#             */
/*   Updated: 2022/09/02 12:28:44 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LI_H
# define T_LI_H

void	li_add_back(t_li **lst, t_li *new);
void	li_clear_one(t_li **li, int content);
void	li_clear(t_li **lst);
t_li	*li_last(t_li *lst);
t_li	*li_new(int content);
int     li_size(t_li *lst);

#endif