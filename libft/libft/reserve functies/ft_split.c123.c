/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/25 21:37:43 by lizhang       #+#    #+#                 */
/*   Updated: 2021/10/01 22:40:57 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_countwords(char const *s, char c)
{
	size_t	words;
	size_t	count;

	words = 0;
	count = 0;
	while (s[count])
	{
		if (s[count] != c && (!s[count + 1] || s[count + 1] == c))
			words++;
		count++;
	}
	return (words);
}

size_t	ft_countchar(char const *s, char c, size_t start)
{
	size_t	wlen;

	wlen = 0;
	while (s[start] && s[start] != c)
	{
		start++;
		wlen++;
	}
	return (wlen);
}

void	ft_cponeword(char *dst, char const *s, size_t start, size_t wlen)
{
	size_t	ccount;

	ccount = 0;
	while (ccount < wlen)
	{
		dst[ccount] = s[start];
		start++;
		ccount++;
	}
}

void	ft_cpwords(char const *s, char c, char **dst, size_t words)
{
	size_t	sccount;
	size_t	wcount;
	size_t	wlen;

	wcount = 0;
	sccount = 0;
	while (wcount < words)
	{
		while (s[sccount] == c)
			sccount++;
		wlen = ft_countchar(s, c, sccount);
		dst[wcount] = ft_calloc(wlen + 1, sizeof(char));
		if (!dst[wcount])
		{
			while (wcount-- > 1)
			{
				free (dst[wcount]);
				dst[wcount] = NULL;
			}
			break ;
		}
		ft_cponeword(dst[wcount], s, sccount, wlen);
		sccount = sccount + wlen + 1;
		wcount++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**dst;
	size_t	words;

	if (!s && c)
	{
		dst = malloc(sizeof(char *));
		if (!dst)
			return (NULL);
		dst[0] = ft_calloc(1, sizeof(char));
		if (!dst[0])
			return (NULL);
		return (dst);
	}
	words = ft_countwords(s, c);
	dst = malloc(sizeof(char *) * (words + 1));
	if (!dst)
		return (NULL);
	ft_cpwords(s, c, dst, words);
	if (!dst[0])
	{
		free (dst);
		return (NULL);
	}
	dst[words] = NULL;
	return (dst);
}
