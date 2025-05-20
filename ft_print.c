/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarques <jmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:25:53 by jmarques          #+#    #+#             */
/*   Updated: 2025/05/20 12:25:56 by jmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putnbr_base_signed(long n, int base, const char *digits)
{
	int				count;
	unsigned long	un;

	count = 0;
	if (n < 0)
	{
		count += print_char('-');
		un = (unsigned long)(-n);
	}
	else
		un = (unsigned long)n;
	count += putnbr_base(un, base, digits);
	return (count);
}

int	putnbr_base(unsigned long n, int base, const char *digits)
{
	int	count;

	count = 0;
	if (n >= (unsigned long)base)
		count += putnbr_base(n / base, base, digits);
	count += print_char(digits[n % base]);
	return (count);
}

int	print_pointer(unsigned long ptr)
{
	int	count;

	count = 0;
	if (!ptr)
	{
		count += print_string("(nil)");
		return (count);
	}
	count += print_string("0x");
	count += putnbr_base(ptr, 16, HEX_LOWER);
	return (count);
}

int	print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	print_string(char *s)
{
	if (!s)
		return (print_string("(null)"));
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}
