/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_padding_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 13:54:13 by igchurru          #+#    #+#             */
/*   Updated: 2025/02/28 14:49:41 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_numlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

void	ft_apply_padding(int pad_len, char pad_char, int *q)
{
	while (pad_len > 0)
	{
		*q += ft_printchar(pad_char, NULL);
		pad_len--;
	}
}

void	ft_left_align(int content_len, int width, int *q, char pad_char)
{
	int pad_len;

	pad_len = width - content_len;
	if (pad_len > 0)
		ft_apply_padding(pad_len, pad_char, q);
}

void	ft_right_align(int content_len, int width, int *q, char pad_char)
{
	int pad_len;

	pad_len = width - content_len;
	if (pad_len > 0)
		ft_apply_padding(pad_len, pad_char, q);
}
