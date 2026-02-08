/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:15:31 by adjelili          #+#    #+#             */
/*   Updated: 2025/11/22 15:22:18 by adjelili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_phex(unsigned long p, char *base, int *count)
{
	if (p < 16)
	{
		ft_print_char(base[p]);
		*(count) = *(count) + 1;
	}
	else
	{
		ft_phex(p / 16, base, count);
		ft_phex(p % 16, base, count);
	}
}

int	ft_print_ptr(void *p)
{
	char	*base;
	int		count;

	count = 0;
	base = "0123456789abcdef";
	if (!p)
	{
		write (1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	ft_phex((unsigned long)p, base, &count);
	return (count + 2);
}
