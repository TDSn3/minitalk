/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 10:00:26 by tda-silv          #+#    #+#             */
/*   Updated: 2022/09/17 11:12:55 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_list_int
{
	int					content;
	struct s_list_int	*prev;
	struct s_list_int	*next;
}	t_li;

typedef struct  s_data_minitalk
{
	int	pid_server;
	int	pid_client;
}   t_data_minitalk;

#endif
