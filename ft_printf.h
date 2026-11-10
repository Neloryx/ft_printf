/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdeglos <thdeglos@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 11:45:45 by thdeglos          #+#    #+#             */
/*   Updated: 2026/10/28 15:14:43 by thdeglos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdarg.h>

int	ft_print_char(int c);
int	ft_print_hex(unsigned long n, int upper);
int	ft_print_nbr(long n);
int	ft_print_ptr(void *ptr);
int	ft_print_str(char *s);
int	ft_printf(const char *format, ...);

#endif
