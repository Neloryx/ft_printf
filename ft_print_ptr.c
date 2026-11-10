/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdeglos <thdeglos@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 11:45:19 by thdeglos          #+#    #+#             */
/*   Updated: 2026/10/28 15:14:11 by thdeglos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(void *ptr)
{
	int	count;
	int	ret;

	if (ptr == NULL)
		return (ft_print_str("(nil)"));
	count = ft_print_str("0x");
	if (count == -1)
		return (-1);
	ret = ft_print_hex((unsigned long) ptr, 0);
	if (ret == -1)
		return (-1);
	return (count + ret);
}
