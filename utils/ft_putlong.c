/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlong.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariafer <mariafer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 10:41:55 by mariafer          #+#    #+#             */
/*   Updated: 2026/06/09 10:41:56 by mariafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putlong(unsigned long nbr, char *base)
{
	int		counter;
	int		base_len;
	int		i;
	char	c[65];

	counter = 0;
	base_len = 0;
	i = 0;
	while (base[base_len])
		base_len++;
	if (nbr == 0)
		return (ft_putchar('0'));
	while (nbr > 0)
	{
		c[i++] = base[nbr % base_len];
		nbr /= base_len;
	}
	while (i > 0)
		counter += write(1, &c[--i], 1);
	return (counter);
}
