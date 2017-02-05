/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 12:09:08 by cpoulet           #+#    #+#             */
/*   Updated: 2017/01/19 16:05:01 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "ft_printf.h"
#include <locale.h>

int	main()
{
	int i;
	long int min;
	long int max;

	min = -15;
	max = 0x10FFFF;

	setlocale(LC_ALL, "");
	i = min;
	while (i <= max)
		ft_printf("%d\n", ft_printf("%C\t", i++));
	return (0);
}
