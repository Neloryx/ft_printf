/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdeglos <thdeglos@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 11:45:26 by thdeglos          #+#    #+#             */
/*   Updated: 2026/10/28 15:14:10 by thdeglos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_digits(unsigned long n)
{
	int	count;
	int	ret;

	count = 0;
	if (n >= 10)
	{
		ret = ft_put_digits(n / 10);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	ret = ft_print_char(n % 10 + '0');
	return (count + ret);
}

int	ft_print_nbr(long n)
{
	int	count;
	int	ret;

	count = 0;
	if (n < 0)
	{
		if (ft_print_char('-') == -1)
			return (-1);
		n = -n;
		count++;
	}
	ret = ft_put_digits(n);
	if (ret == -1)
		return (-1);
	return (count + ret);
}
