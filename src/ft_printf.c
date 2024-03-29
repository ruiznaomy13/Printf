/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:07:25 by ncastell          #+#    #+#             */
/*   Updated: 2023/12/07 16:59:02 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"

int	ft_format(char c, va_list args, int ln)
{
	if (c == '%')
		ln += ft_put_char('%');
	if (c == 'c')
		ln += ft_put_char(va_arg(args, int));
	if (c == 's')
		ln += ft_put_str(va_arg(args, char *));
	if (c == 'i' || c == 'd')
		ln = ft_put_nums(va_arg(args, int), ln);
	if (c == 'u')
		ln = ft_put_nums(va_arg(args, unsigned int), ln);
	if (c == 'X' || c == 'x')
		ln = ft_put_hex(va_arg(args, unsigned int), c, ln);
	if (c == 'p')
	{
		if (write(1, "0x", 2) == -1)
			return (-1);
		ln += 2;
		ln = ft_put_pointer(va_arg(args, unsigned long), ln);
	}
	return (ln);
}

int	ft_printf(char const *str, ...)
{
	int		i;
	va_list	params;
	int		print_ln;

	va_start(params, str);
	i = 0;
	print_ln = 0;
	while (str[i])
	{
		if (str[i] == '%' && (str[i + 1] != '\\'))
		{
			i++;
			print_ln = ft_format(str[i], params, print_ln);
		}
		else
			print_ln += ft_put_char(str[i]);
		if (print_ln == -1)
			return (-1);
		i++;
	}
	va_end(params);
	return (print_ln);
}
