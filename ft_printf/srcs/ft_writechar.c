  /* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_writechar.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/31 19:00:19 by lizhang       #+#    #+#                 */
/*   Updated: 2021/11/02 19:57:41 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printflibft.h"

int	ft_writechar(va_list ap)
{
	char	cw;

	cw = (char)va_arg(ap, int);
	write(1, &cw, 1);
	return (1);
}
