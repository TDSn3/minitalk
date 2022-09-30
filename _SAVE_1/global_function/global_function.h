/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_function.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:26:54 by tda-silv          #+#    #+#             */
/*   Updated: 2022/09/30 12:44:29 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_FUNCTION_H
# define GLOBAL_FUNCTION_H

void	find_size_pid(int n, size_t *size_pid);
char	*add_zero(char **str);
void	conv_size_bin(char *str, int pid, size_t size_pid_client);
void	stetup_struct(t_data *g_d);
int		conv_oct_int(char *str);
void    conv_str_bin(char *str);

#endif
