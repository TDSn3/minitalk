/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_dl.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 12:19:00 by tda-silv          #+#    #+#             */
/*   Updated: 2022/10/14 19:13:33 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_DL_H
# define T_DL_H

int		dl_add_back(t_dl **lst, t_dl *new);
void	dl_clear_one(t_dl **li, int content);
void	dl_clear(t_dl **lst);
t_dl	*dl_last(t_dl *lst);
t_dl	*dl_new(int content);
int		dl_size(t_dl *lst);
t_li	*dl_find_pid(t_dl *client_connected, int pid);

#endif