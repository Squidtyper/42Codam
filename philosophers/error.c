/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/29 01:22:59 by lizhang       #+#    #+#                 */
/*   Updated: 2022/10/28 19:26:20 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	acerror(int ac)
{
	if (ac != 5 && ac != 6)
	{
		printf("please input 4 or 5 arguments\n");
		return (-1);
	}
	else
		return (1);
}

int	averror(char **av)
{
	int	c1;
	int	c2;

	c1 = 1;
	while (av[c1])
	{
		c2 = 0;
		while (av[c1][c2])
		{
			if (av[c1][c2] < 48 || av[c1][c2] > 57)
			{
				printf("please input positive and whole numbers");
				return (-1);
			}
			c2++;
		}
		c1++;
	}
	return (1);
}

int	nerror(t_group *g)
{
	if (g->n < 1 || g->n > 500 || g->ttd < 0 \
	|| g->tte < 0 || g->tts < 0 || g->xtimes > 500)
	{
		printf("please input reasonable value");
		return (-1);
	}
	else
		return (1);
}
