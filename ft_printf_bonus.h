/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:41:55 by igchurru          #+#    #+#             */
/*   Updated: 2025/02/04 17:30:42 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H

# define FT_PRINTF_BONUS_H

# include <unistd.h>
# include <stdarg.h>

# define NO 0
# define YES 1 

typedef struct s_format
{
	int		zero_padding;
	int		blank_padding;
	int		pad_field;
	int		align_left;
	int		hashtag;
	int		space_sign;
	int		plus_sign;
	char	d;
}	t_format;

//	FT_PRINTF_BONUS.C
int		ft_printf(char const *str, ...);

//	FT_PRINTF_FORMAT_BONUS.C
void	*ft_memset(void *b, int c, size_t len);

#endif