/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariafer <mariafer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 10:41:19 by mariafer          #+#    #+#             */
/*   Updated: 2026/06/09 10:41:20 by mariafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putint(int nbr)
{
	int		counter;
	long	n;

	counter = 0;
	n = nbr;
	if (n < 0)
	{
		counter += write(1, "-", 1);
		n *= -1;
	}
	counter += ft_putlong((unsigned long)n, "0123456789");
	return (counter);
}
