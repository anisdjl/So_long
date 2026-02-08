/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 10:09:22 by adjelili          #+#    #+#             */
/*   Updated: 2025/11/22 17:41:14 by adjelili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printmin(long nb, char *base, int *count, char c)
{
	if (nb < 16)
	{
		ft_print_char(base[nb]);
		*(count) = *(count) + 1;
	}
	else
	{
		ft_printmin(nb / 16, base, count, c);
		ft_printmin(nb % 16, base, count, c);
	}
}

static void	ft_printmax(long nb, char *base, int *count, char c)
{
	if (nb < 16)
	{
		ft_print_char(base[nb]);
		*(count) = *(count) + 1;
	}
	else
	{
		ft_printmax(nb / 16, base, count, c);
		ft_printmax(nb % 16, base, count, c);
	}
}

int	ft_print_hex(unsigned int n, char c)
{
	int		count;
	char	*base;
	long	nb;

	count = 0;
	nb = n;
	if (c == 'x')
	{
		base = "0123456789abcdef";
		ft_printmin(nb, base, &count, c);
	}
	else if (c == 'X')
	{
		base = "0123456789ABCDEF";
		ft_printmax(nb, base, &count, c);
	}
	return (count);
}
