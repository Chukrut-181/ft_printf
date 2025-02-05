/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:50:24 by igchurru          #+#    #+#             */
/*   Updated: 2025/02/05 11:24:19 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	i;
	int	j;

	i = ft_printf("Testing 'i' case: |%7i|\n", 42);
	j = printf("Testing 'i' case: |%7i|\n", 42);
	ft_printf("Retorno: %i = %i\n", i, j);
	return (0);
}
/* cc -Wall -Wextra -Werror main.c && ./a.out */