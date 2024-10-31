/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 09:59:32 by igchurru          #+#    #+#             */
/*   Updated: 2024/10/31 09:00:41 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// <unistd.h> - Provides the `write` function.
// <stdarg.h> - Provides macros to access variable arguments 
//              (va_list, va_start, va_arg, va_end).
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(char const *str, ...);

int	ft_printchar(char c, int q);
int	ft_printstr(char *str, int q);
int	ft_printhex(unsigned long n, int q, char h);
int	ft_printnbr(int n, int q);
int	ft_printunsnbr(unsigned int n, int q);

#endif
