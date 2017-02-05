/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 12:09:08 by cpoulet           #+#    #+#             */
/*   Updated: 2017/01/22 15:31:20 by cpoulet          ###   ########.fr       */
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
		printf("%d\n", printf("%C\t", L'🐒'));
	return (0);
}
