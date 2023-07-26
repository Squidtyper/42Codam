/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/29 18:56:54 by lizhang       #+#    #+#                 */
/*   Updated: 2022/10/28 21:50:36 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	aton(const char *str)
{
	long long	c;
	long long	d;
	long long	r;

	c = 0;
	d = 0;
	r = 0;
	if (!str)
		return (-1);
	while (str[c])
		c++;
	while (d < c)
	{
		r = r * 10 - (str[d] - 48);
		d++;
	}
	r = -r;
	return (r);
}

long long	gettime(long long time0)
{
	struct timeval	ct;
	long long		time;

	gettimeofday(&ct, NULL);
	time = ct.tv_sec * 1000 + (ct.tv_usec / 1000) - time0;
	return (time);
}

void	joinall(t_group *g)
{
	int	i;

	i = 0;
	while (i < g->n)
	{
		pthread_join(g->philo[i].tid, NULL);
		i++;
	}
}

void	stepsleep(long long time)
{
	long long	starttime;

	starttime = gettime(0);
	while ((gettime(0) - starttime) < time / 1000)
		usleep(100);
}
