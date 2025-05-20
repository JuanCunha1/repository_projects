/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarques <jmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:58:45 by jmarques          #+#    #+#             */
/*   Updated: 2025/05/20 12:31:35 by jmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBPRINTF_H
# define LIBPRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

# define HEX_LOWER	"0123456789abcdef"
# define HEX_UPPER	"0123456789ABCDEF"
# define INT_BASE	"0123456789"

int	ft_printf(const char *input, ...);
int	putnbr_base(unsigned long n, int base, const char *digits);
int	print_pointer(unsigned long value);
int	print_string(char *s);
int	print_char(char c);
int	putnbr_base_signed(long int n, int base, const char *digits);

#endif
