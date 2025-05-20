/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarques <jmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:58:45 by jmarques          #+#    #+#             */
/*   Updated: 2025/05/15 14:27:38 by jmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

static int	check_type(const char input, va_list args)
{
	int	i;

	i = 0;
	if (input == 'c')
		i += print_char(va_arg(args, int));
	else if (input == 's')
		i += print_string(va_arg(args, char *));
	else if (input == 'p')
		i += print_pointer((unsigned long)va_arg(args, void *));
	else if (input == 'd' || input == 'i')
		i += putnbr_base(va_arg(args, long int), 10, INT_BASE);
	else if (input == 'u')
		i += putnbr_base(va_arg(args, unsigned int), 10, INT_BASE);
	else if (input == 'x')
		i += putnbr_base(va_arg(args, unsigned int), 16, HEX_LOWER);
	else if (input == 'X')
		i += putnbr_base(va_arg(args, unsigned int), 16, HEX_UPPER);
	else if (input == '%')
		i += print_char('%');
	return (i);
}

int	ft_printf(const char *input, ...)
{
	int		i;
	va_list	args;

	i = 0;
	va_start(args, input);
	while (*input)
	{
		if (*input == '%')
		{
			input++;
			if (*input)
			{
				i += check_type(*input, args);
			}
			else
				break ;
		}
		else
			i += print_char(*input);
		input++;
	}
	va_end(args);
	return (i);
}
/*
#include <stdio.h>
int main()
{
	int *ptr = NULL;
	int count =0;
	char *ct = NULL;
	count =ft_printf("%c,%d,%s %i,%x %X %p\n",'a', 12, ct, 16,77,77,ptr);
	ft_printf("count = %d\n",count);
	count = printf("%c,%d,%s %i,%x %X %p\n",'a', 12, ct, 16,77,77,ptr);
	ft_printf("count = %d\n",count);
	int num = 42;
    ptr = &num;
    count = ft_printf("%c,%d,%s %i,%x %X %p\n",'a', 12, "deu", 16,77,77,ptr);
    ft_printf("count = %d\n",count);
	count = printf("%c,%d,%s %i,%x %X %p\n",'a', 12, "deu", 16,77,77,ptr);
	ft_printf("count = %d\n",count);
	return 0;
}
*/
