/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:58:46 by igchurru          #+#    #+#             */
/*   Updated: 2025/02/18 16:12:02 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_printchar(char c, t_format *format)
{
	int count;
	int padding;

	if (!format)
		return(write(1, &c, 1));
	count = 0;
	padding = format->width - 1;
	while (padding > 0 && !(format->flags & FLAG_MINUS))
	{
		count += write(1, " ", 1);
		padding--;
	}
	count += write(1, &c, 1);
	while (padding > 0 && format->flags & FLAG_MINUS)
	{
		count += write(1, " ", 1);
		padding--;
	}
	return (count);
}
