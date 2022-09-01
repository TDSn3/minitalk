/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_child.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 11:56:10 by tda-silv          #+#    #+#             */
/*   Updated: 2022/09/01 12:45:12 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_CHILD_H
# define SERVER_CHILD_H

void	s_conv_str_bin(char *argv[], int pid_client);
void	s_send_signal(char *str, int pid_client);

#endif
