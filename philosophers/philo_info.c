/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_info.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/09 14:57:32 by lizhang       #+#    #+#                 */
/*   Updated: 2022/10/28 19:00:33 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_gen(t_group *g)
{
	int	i;

	i = 0;
	g->philo = (t_philo *)malloc(g->n * sizeof(t_philo));
	while (g->philo && i < g->n)
	{
		g->philo[i].id = i;
		g->philo[i].chop1 = i;
		g->philo[i].chop2 = (i + 1) % g->n;
		g->philo[i].lastmeal = gettime(g->time0);
		if (i % 2 == 0)
			g->philo[i].state = 3;
		else
			g->philo[i].state = 2;
		g->philo[i].fin = g->xtimes;
		g->philo[i].group = g;
		i++;
	}
}

void	mutex_gen(t_group *g)
{
	int	i;

	i = 0;
	g->chops = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * g->n);
	if (!g->chops)
		return ;
	while (i < g->n)
	{
		pthread_mutex_init(&g->chops[i], NULL);
		pthread_mutex_init(&g->philo[i].fmutex, NULL);
		pthread_mutex_init(&g->philo[i].lmutex, NULL);
		i++;
	}
	pthread_mutex_init(&g->dmutex, NULL);
}

t_group	*parseinput(int ac, char **av)
{
	t_group	*g;

	if (acerror(ac) == -1 || averror(av) == -1)
		return (NULL);
	g = (t_group *)malloc(sizeof(t_group));
	if (!g)
		return (NULL);
	g->n = aton(av[1]);
	g->ttd = aton(av[2]) * 1000;
	g->tte = aton(av[3]) * 1000;
	g->tts = aton(av[4]) * 1000;
	g->xtimes = aton(av[5]);
	g->time0 = gettime(0);
	g->dead = 1;
	if (nerror(g) == -1)
	{
		free(g);
		return (NULL);
	}
	return (g);
}
