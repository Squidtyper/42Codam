/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_writevoid.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/31 19:36:38 by lizhang       #+#    #+#                 */
/*   Updated: 2021/11/02 23:20:07 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printflibft.h"

int	ft_writevoid(va_list ap)
{
	void	*v;

	v = va_arg(ap, void *);
	write(1, "0x", 2);
	if (v == (void *) -1)
		return (2 + ft_writehex(SIZE_MAX, 0));
	return (2 + ft_writehex((long long int)v, 0));
}
