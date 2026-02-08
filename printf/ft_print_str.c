/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 10:17:48 by adjelili          #+#    #+#             */
/*   Updated: 2025/11/22 15:22:12 by adjelili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *str)
{
	int	y;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	y = 0;
	while (str[y])
	{
		write(1, &str[y], 1);
		y++;
	}
	return (y);
}

/*#include <stdio.h>
int main(void)
{
	char str[6] = "hello";

	printf("%d\n", ft_print_str(str));
	return (0);
}*/