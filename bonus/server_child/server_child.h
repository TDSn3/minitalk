/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_child.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 11:56:10 by tda-silv          #+#    #+#             */
/*   Updated: 2022/10/14 19:02:13 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_CHILD_H
# define SERVER_CHILD_H

void	s_send_signal(char *str, int pid_client);
void	s_setup_struct(t_s_data_minitalk *g_d);
int     s_check_null_li(t_dl **list, int pid);

#endif
