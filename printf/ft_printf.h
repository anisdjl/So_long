/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anis <anis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 10:41:51 by adjelili          #+#    #+#             */
/*   Updated: 2025/11/22 22:02:59 by anis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

int	ft_print_int(int n);
int	ft_test_format(char c, va_list *args);
int	ft_printf(const char *s, ...);
int	ft_print_char(char c);
int	ft_print_str(char *str);
int	ft_print_uint(unsigned int n);
int	ft_print_hex(unsigned int n, char c);
int	ft_print_ptr(void *p);

#endif