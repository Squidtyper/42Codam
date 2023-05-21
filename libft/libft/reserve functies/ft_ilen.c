/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ilen.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/25 19:11:38 by lizhang       #+#    #+#                 */
/*   Updated: 2021/08/17 19:53:43 by liwenzhan     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_ilen(int n)
{
	size_t	len;

	len = 1;
	while (n <= -10 || n >= 10)
	{
		n = n / 10;
		len++;
	}
	return (len);
}
