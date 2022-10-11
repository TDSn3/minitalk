/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 18:27:51 by tda-silv          #+#    #+#             */
/*   Updated: 2022/10/11 12:38:39 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

size_t	ft_strlen(const char *s);
int		ft_atoi(const char *nptr);
char	*ft_itoa_two(int n);
char	*ft_itoa_ten(int n);
char	*ft_strjoin(char **s1, char **s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

#endif
