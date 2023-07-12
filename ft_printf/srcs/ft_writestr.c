/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_writestr.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/31 19:09:31 by lizhang       #+#    #+#                 */
/*   Updated: 2021/11/02 21:55:48 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printflibft.h"

int	ft_writestr(va_list ap)
{
	char	*sw;

	sw = va_arg(ap, char *);
	if (!sw)
		return (ft_writenull(sw));
	if (sw)
	{
		ft_putstr_fd(sw, 1);
		return (ft_strlen(sw));
	}
	return (0);
}
