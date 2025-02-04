/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 09:59:32 by igchurru          #+#    #+#             */
/*   Updated: 2025/02/04 15:25:01 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(char const *str, ...);

int		ft_printchar(char c);
void	ft_printstr(char *str, int *q);
void	ft_printhex(unsigned long n, int *q, char h);
void	ft_printnbr(int n, int *q);
void	ft_printunsnbr(unsigned int n, int *q);

#endif
