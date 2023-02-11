/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 22:19:58 by ncastell          #+#    #+#             */
/*   Updated: 2023/01/28 14:20:23 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int		ft_put_char(int c);
int		ft_put_str(char *str);
int		ft_put_int(int num);
int		ft_put_unint(unsigned int num);
#endif
