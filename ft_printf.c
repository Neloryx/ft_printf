/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdeglos <thdeglos@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 11:45:39 by thdeglos          #+#    #+#             */
/*   Updated: 2026/11/10 15:42:05 by thdeglos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_dispatch(char c, va_list *args)
{
	if (c == 'c')
		return (ft_print_char(va_arg(*args, int)));
	if (c == 's')
		return (ft_print_str(va_arg(*args, char *)));
	if (c == 'p')
		return (ft_print_ptr(va_arg(*args, void *)));
	if (c == 'd' || c == 'i')
		return (ft_print_nbr(va_arg(*args, int)));
	if (c == 'u')
		return (ft_print_nbr(va_arg(*args, unsigned int)));
	if (c == 'x')
		return (ft_print_hex(va_arg(*args, unsigned int), 0));
	if (c == 'X')
		return (ft_print_hex(va_arg(*args, unsigned int), 1));
	if (c == '%')
		return (ft_print_char('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		ret;

	va_start(args, format);
	count = 0;
	if (format == NULL)
		return (-1);
	while (*format)
	{
		if (*format == '%' && format[1])
		{
			format++;
			ret = ft_dispatch(*format, &args);
		}
		else
			ret = ft_print_char(*format);
		if (ret == -1)
			return (va_end(args), -1);
		count += ret;
		format++;
	}
	va_end(args);
	return (count);
}
