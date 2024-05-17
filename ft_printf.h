/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 09:59:32 by igchurru          #+#    #+#             */
/*   Updated: 2024/05/17 14:47:11 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int	ft_printf(char const *str, ...);

int	ft_printchar(char c, int q);
int	ft_printstr(char *str, int q);
int	ft_printhex(unsigned long n, int q, char h);
int	ft_printnbr(int n, int q);
int	ft_printunsnbr(unsigned int n, int q);

#endif
