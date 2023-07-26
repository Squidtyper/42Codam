/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 15:40:22 by lizhang       #+#    #+#                 */
/*   Updated: 2022/10/28 21:53:27 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//r is 0 for reading, r is 1 for writing
//value return: 0 for read death, 1 for read alive, 2 for written death
int	checkfinish(t_group *g)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (i < g->n)
	{
		check = check + accessf(&g->philo[i], 0);
		i++;
	}
	if (check == g->n)
	{
		accessd(g, 1);
		return (1);
	}
	else
		return (-1);
}

void	*checkdeath(void *group)
{
	int			i;
	t_group		*g;
	long long	ct;

	usleep(100);
	g = (t_group *)group;
	while (checkfinish(g) < 0 && accessd(g, 0) == 1)
	{
		i = 0;
		while (i < g->n)
		{
			usleep(100);
			ct = gettime(g->time0);
			if ((ct - accessmeal(&g->philo[i], 0, 0)) > (g->ttd / 1000))
			{
				accessd(g, 1);
				printf("%lld: philosopher %d has died\n", ct, i);
				return (NULL);
			}
			i++;
		}
	}
	return (NULL);
}
