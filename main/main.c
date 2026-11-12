/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdeglos <thdeglos@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 12:35:28 by thdeglos          #+#    #+#             */
/*   Updated: 2026/11/10 15:50:00 by thdeglos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include <errno.h>
#include "../ft_printf.h"
 
int	main(void)
{
	int	ret1;
	int	ret2;
	int	x = 42;
 
	/* %c */
	ret1 = printf("printf    : [%c]\n", 'a');
	ret2 = ft_printf("ft_printf : [%c]\n", 'a');
	printf("ret: %d | %d\n\n", ret1, ret2);
 
	/* %s */
	ret1 = printf("printf    : [%s]\n", "Hello 42");
	ret2 = ft_printf("ft_printf : [%s]\n", "Hello 42");
	printf("ret: %d | %d\n\n", ret1, ret2);
 
	/* %s NULL */
	ret1 = printf("printf    : [%s]\n", (char *)NULL);
	ret2 = ft_printf("ft_printf : [%s]\n", (char *)NULL);
	printf("ret: %d | %d\n\n", ret1, ret2);
 
	/* %p */
	ret1 = printf("printf    : [%p]\n", &x);
	ret2 = ft_printf("ft_printf : [%p]\n", &x);
	printf("ret: %d | %d\n\n", ret1, ret2);
 
	/* %p NULL */
	ret1 = printf("printf    : [%p]\n", NULL);
	ret2 = ft_printf("ft_printf : [%p]\n", NULL);
	printf("ret: %d | %d\n\n", ret1, ret2);
 
	/* %d */
	ret1 = printf("printf    : [%d] [%d] [%d]\n", 0, INT_MAX, INT_MIN);
	ret2 = ft_printf("ft_printf : [%d] [%d] [%d]\n", 0, INT_MAX, INT_MIN);
	printf("ret: %d | %d\n\n", ret1, ret2);
 
	/* %i */
	ret1 = printf("printf    : [%i] [%i]\n", 42, -42);
	ret2 = ft_printf("ft_printf : [%i] [%i]\n", 42, -42);
	printf("ret: %d | %d\n\n", ret1, ret2);
 
	/* %u */
	ret1 = printf("printf    : [%u] [%u]\n", 42, -1);
	ret2 = ft_printf("ft_printf : [%u] [%u]\n", 42, -1);
	printf("ret: %d | %d\n\n", ret1, ret2);
 
	/* %x */
	ret1 = printf("printf    : [%x] [%x]\n", 255, -1);
	ret2 = ft_printf("ft_printf : [%x] [%x]\n", 255, -1);
	printf("ret: %d | %d\n\n", ret1, ret2);
 
	/* %X */
	ret1 = printf("printf    : [%X] [%X]\n", 255, -1);
	ret2 = ft_printf("ft_printf : [%X] [%X]\n", 255, -1);
	printf("ret: %d | %d\n\n", ret1, ret2);
 
	/* %% */
	ret1 = printf("printf    : [100%%]\n");
	ret2 = ft_printf("ft_printf : [100%%]\n");
	printf("ret: %d | %d\n\n", ret1, ret2);
 
	/* mix */
	ret1 = printf("printf    : %c %s %d %u %x %X %%\n", 'z', "mix", -1, 1, 255, 255);
	ret2 = ft_printf("ft_printf : %c %s %d %u %x %X %%\n", 'z', "mix", -1, 1, 255, 255);
	printf("ret: %d | %d\n\n", ret1, ret2);
 
	/* test [%] */
	ft_printf("ft_printf : [%]");

	/* test NULL */
	printf(NULL);
	ft_printf(NULL);

	/* test stdout closed */
	close(1);
	
	errno = 0;
	ret1 = printf("printf    : %d\n", 42);
	int errno_ret1 = errno;
	ret2 = ft_printf("printf    : %d\n", 42);
	int errno_ret2 = errno;

	fprintf(stderr, "printf    : ret = %d, errno = %d\n", ret1, errno_ret1);
	fprintf(stderr, "ft_printf    : ret = %d, errno = %d\n", ret2, errno_ret2);
	
	return (0);
}
