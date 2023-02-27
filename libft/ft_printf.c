/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsousa <thsousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:05:10 by thsousa           #+#    #+#             */
/*   Updated: 2022/08/23 13:13:21 by thsousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_type(char *str, va_list list, int i)
{
	if (str[i + 1] == 'c')
		return (put_char(va_arg(list, int)));
	if (str[i + 1] == 's')
		return (put_str(va_arg(list, char *)));
	if (str[i + 1] == 'p')
		return (write(1, "0x", 2) + put_ptr(va_arg(list, unsigned long)));
	if ((str[i + 1] == 'd') || (str[i + 1] == 'i'))
		return (put_itoa(va_arg(list, int)));
	if (str[i + 1] == 'u')
		return (put_utoa(va_arg(list, unsigned int)));
	if (str[i + 1] == 'x')
		return (put_hexa(va_arg(list, unsigned int)));
	if (str[i + 1] == 'X')
		return (put_hexa_up(va_arg(list, unsigned int)));
	if (str[i + 1] == '%')
		return (put_char('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		count;
	int		i;

	i = 0;
	count = 0;
	va_start(list, str);
	while (str[i])
	{
		if (str[i] == '%' && ft_find("cspdiuxX%", str[i + 1]))
		{
			count += ft_type((char *)str, list, i);
			i++;
		}
		else
			count += put_char(str[i]);
		i++;
	}
	va_end(list);
	return (count);
}
