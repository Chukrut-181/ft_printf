/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:50:24 by igchurru          #+#    #+#             */
/*   Updated: 2025/02/05 13:46:44 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	i;
	int	j;

	i = ft_printf("Testing 'i' case: |%10i|\n", -4299);
	j = printf("Testing 'i' case: |%10i|\n", -4299);
	ft_printf("Retorno: %d = %d\n", i, j);
	return (0);
}
/* cc -Wall -Wextra -Werror main.c libftprintf.a && ./a.out */