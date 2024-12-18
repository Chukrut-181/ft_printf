/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:50:24 by igchurru          #+#    #+#             */
/*   Updated: 2024/12/18 10:56:52 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int		i;
	int 	j;
	char	*string = "olakease";
	char	*null_ptr = NULL;

	i = ft_printf("Test c: %c\n", 'W');
	j = printf("Test c: %c\n", 'W');
	ft_printf("%i = %i\n\n", i, j);

	i = ft_printf("Test s: %s - %s - %s\n", string, "ytukienere", null_ptr);
	j = printf("Test s: %s - %s - %s\n", string, "ytukienere", null_ptr);
	ft_printf("%i = %i\n\n", i, j);

	i = ft_printf("Test p: %p - %p\n", string, null_ptr);
	j = printf("Test p: %p - %p\n", string, null_ptr);
	ft_printf("%i = %i\n\n", i, j);

	i = ft_printf("Test d: %d - %d - %d\n", 42, -42, 0);
	j = printf("Test d: %d - %d - %d\n", 42, -42, 0);
	ft_printf("%i = %i\n\n", i, j);

	i = ft_printf("Test i: %i - %i - %i\n", 84, -84, 0);
	j = printf("Test i: %i - %i - %i\n", 84, -84, 0);
	ft_printf("%i = %i\n\n", i, j);

	i = ft_printf("Test u: %u - %u\n", 7898, 0);
	j = printf("Test u: %u - %u\n", 7898, 0);
	ft_printf("%i = %i\n\n", i, j);

	i = ft_printf("Test x: %x\n", 652998700);
	j = printf("Test x: %x\n", 652998700);
	ft_printf("%i = %i\n\n", i, j);

	i = ft_printf("Test X: %X\n", 652998700);
	j = printf("Test X: %X\n", 652998700);
	ft_printf("%i = %i\n\n", i, j);

	i = ft_printf("Test %%: %%\n");
	j = printf("Test %%: %%\n");
	ft_printf("%i = %i\n\n", i, j);

	i = ft_printf("%c la prueba con el 65%% de los %i %s. Vemos los punteros válido %p y nulo %p.\n ", 'Y', 9, "tests", string, null_ptr);
	j = printf("%c la prueba con el 65%% de los %i %s. Vemos los punteros válido %p y nulo %p.\n ", 'Y', 9, "tests", string, null_ptr);
	ft_printf("%i = %i\n\n", i, j);

	return (0);
}
/* cc -Wall -Wextra -Werror main.c libftprintf.a && ./a.out */