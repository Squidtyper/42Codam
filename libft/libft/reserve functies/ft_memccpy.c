/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/13 17:45:03 by lizhang       #+#    #+#                 */
/*   Updated: 2021/09/05 21:52:45 by liwenzhan     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	loc;
	char	*s;
	char	*d;

	loc = 0;
	d = (char *)dst;
	s = (char *)src;
	if (!src)
		return (NULL);
	while (s[loc] != c && loc < n)
	{
		d[loc] = s[loc];
		loc++;
	}
	if (loc == n)
		return (NULL);
	d[loc] = s[loc];
	dst = d;
	return (d + loc + 1);
}
