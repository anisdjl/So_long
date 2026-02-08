/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anis <anis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 09:24:38 by adjelili          #+#    #+#             */
/*   Updated: 2025/11/22 21:24:04 by anis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count(int n)
{
	int	count;

	count = 0;
	if (n == 0)
	{
		count = 1;
		return (count);
	}
	if (n < 0)
		count++;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

int	ft_print_int(int n)
{
	long	nb;
	int		count;

	count = 0;
	nb = n;
	if (nb == -2147483648)
		ft_print_str("-2147483648");
	else if (nb < 0)
	{
		ft_print_char('-');
		nb = -nb;
		ft_print_int(nb);
	}
	else if (nb >= 10)
	{
		ft_print_int(nb / 10);
		ft_print_int(nb % 10);
	}
	else
		ft_print_char(nb + '0');
	return (ft_count(n));
}

// #include <stdio.h>
// int main(void)
// {
// 	int n = 4;
// 	//printf("%d", ft_print_int(n));
// 	//ft_print_int(n);
// 	printf("      %d", ft_print_int(n));
// 	return (0);
// }
