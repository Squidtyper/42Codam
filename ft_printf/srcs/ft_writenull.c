/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_writenull.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/02 21:47:58 by lizhang       #+#    #+#                 */
/*   Updated: 2021/11/02 21:51:02 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printflibft.h"
int	ft_writenull(char *str)
{
	if (!str)
		write(1, "(null)", 6);
	return (6);
}
