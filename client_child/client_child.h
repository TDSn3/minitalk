/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_child.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 11:54:06 by tda-silv          #+#    #+#             */
/*   Updated: 2022/10/10 17:54:34 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_CHILD_H
# define CLIENT_CHILD_H

int 	c_check_error(int argc, char *argv[]);
void	c_send_signal(char *str, int pid_server);
void	c_conv_str_bin(char *argv[], int pid_server);
void	c_setup_struct(t_c_data_minitalk *g_d);
void    c_send_str_signal(char *str, int pid_client, int pid_server);

#endif
