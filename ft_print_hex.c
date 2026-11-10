/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdeglos <thdeglos@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 11:45:29 by thdeglos          #+#    #+#             */
/*   Updated: 2026/10/28 15:14:08 by thdeglos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned long n, int upper)
{
	char	*base;
	int		count;
	int		ret;

	if (upper)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	count = 0;
	if (n >= 16)
	{
		ret = ft_print_hex(n / 16, upper);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	ret = write(1, &base[n % 16], 1);
	if (ret == -1)
		return (-1);
	return (count + ret);
}
