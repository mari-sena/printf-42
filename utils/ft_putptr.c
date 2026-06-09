/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariafer <mariafer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 10:13:06 by mariafer          #+#    #+#             */
/*   Updated: 2026/06/09 10:13:07 by mariafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putptr(void *ptr)
{
	int	counter;

	counter = 0;
	if (!ptr)
		return (ft_putstr("(nil)"));
	counter += ft_putstr("0x");
	counter += ft_putlong((unsigned long)ptr, "0123456789abcdef");
	return (counter);
}
