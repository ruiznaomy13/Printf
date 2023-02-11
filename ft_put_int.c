/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 13:31:29 by ncastell          #+#    #+#             */
/*   Updated: 2023/01/28 14:12:53 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "Libft/libft.h"

int	ft_put_int(int	num)
{
	int		i;
	char	*number;

	number = ft_itoa(num);
	i = 0;
	while (number[i]){
		write (1, &number[i], 1);
			i++;
	}
	return (i);
}
