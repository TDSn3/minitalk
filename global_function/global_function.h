/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_function.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:26:54 by tda-silv          #+#    #+#             */
/*   Updated: 2022/10/14 19:10:47 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_FUNCTION_H
# define GLOBAL_FUNCTION_H

char	*add_zero(char **str);
int		conv_oct_int(char *str);
char	*conv_str_bin(char *str);
int		clear_error_exit(t_dl **client_connected, int choice);

#endif
