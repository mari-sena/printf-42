/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariafer <mariafer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 19:01:51 by mariafer          #+#    #+#             */
/*   Updated: 2026/06/06 19:01:52 by mariafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_cases(char c, va_list ap)
{
	if (c == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (c == 'p')
		return (ft_putptr(va_arg(ap, void *)));
	else if (c == 'd' || (c == 'i'))
		return (ft_putint(va_arg(ap, int)));
	else if (c == 'u')
		return (ft_putlong(va_arg(ap, unsigned int), "0123456789"));
	else if (c == 'x')
		return (ft_putlong(va_arg(ap, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_putlong(va_arg(ap, unsigned int), "0123456789ABCDEF"));
	else if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	validate_cases(char *s, char c)
{
	while (*s)
	{
		if (*s++ == c)
			return (1);
	}
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int	len;

	if (!s)
		return (0);
	len = 0;
	va_start(ap, s);
	while (*s)
	{
		if (*s == '%' && validate_cases("cspdiuxX", *(s + 1)))
		{
			s++;
			len += convert_cases(*s, ap);
		}
		else
			len += ft_putchar(*s);
	}
	va_end(ap);
	return (len);
}
