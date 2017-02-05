/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 12:09:08 by cpoulet           #+#    #+#             */
/*   Updated: 2017/01/22 14:09:55 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "ft_printf.h"
#include <locale.h>



int	main()
{
	char *str;

	ft_printf("ceci est "RED"|%S|\n"EOC, L"🧀 🧀 ");
	setlocale(LC_ALL, "");
	ft_printf("|%Ld|\n", 48);
	return (0);
}
