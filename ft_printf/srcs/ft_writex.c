/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_writex.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/31 20:17:47 by lizhang       #+#    #+#                 */
/*   Updated: 2021/10/31 20:42:09 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printflibft.h"

int	ft_writex(va_list ap, int caseind)
{
	unsigned int	uiw;
	int				count;

	uiw = va_arg(ap, unsigned int);
	count = ft_writehex((long long int)uiw, caseind);
	return (count);
}
