/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:50:24 by igchurru          #+#    #+#             */
/*   Updated: 2025/02/07 14:01:52 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	i;
	int	j;
	char *test_str = "olakease";

	i = ft_printf("Testing 'i' case: |%10i|\n", 42);
	j = printf("Testing 'i' case: |%10i|\n", 42);
	ft_printf("Retorno: %d = %d\n\n", i, j);

	i = ft_printf("Testing 's' case: |%12s|\n", test_str);
	j = printf("Testing 's' case: |%12s|\n", test_str);
	ft_printf("Retorno: %d = %d\n\n", i, j);

	i = ft_printf("Testing 'x' case: |%12x|\n", 987654);
	j = printf("Testing 'x' case: |%12x|\n", 987654);
	ft_printf("Retorno: %d = %d\n", i, j);

	
	return (0);
}
/* cc -Wall -Wextra -Werror main.c libftprintf.a && ./a.out */