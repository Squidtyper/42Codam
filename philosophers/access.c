/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   access.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 21:35:59 by lizhang       #+#    #+#                 */
/*   Updated: 2023/06/01 17:06:55 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	accessmeal(t_philo *philo, int r, long long replace)
{
	long long	lastmeal;

	lastmeal = 0;
	if (r == 0)
	{
		pthread_mutex_lock(&philo->lmutex);
		lastmeal = philo->lastmeal;
		pthread_mutex_unlock(&philo->lmutex);
	}
	else
	{
		pthread_mutex_lock(&philo->lmutex);
		philo->lastmeal = replace;
		pthread_mutex_unlock(&philo->lmutex);
	}
	return (lastmeal);
}

int	accessd(t_group *g, int r)
{
	int	value;

	if (r == 0)
	{
		pthread_mutex_lock(&(g->dmutex));
		value = g->dead;
		pthread_mutex_unlock(&(g->dmutex));
	}
	else
	{
		pthread_mutex_lock(&(g->dmutex));
		g->dead = 0;
		value = 2;
		pthread_mutex_unlock(&(g->dmutex));
	}
	return (value);
}

int	accessf(t_philo *philo, int r)
{
	int	check;

	check = 0;
	if (r == 0)
	{
		pthread_mutex_lock(&philo->fmutex);
		if (philo->fin == 0)
			check++;
		pthread_mutex_unlock(&philo->fmutex);
		return (check);
	}
	else
	{
		pthread_mutex_lock(&philo->fmutex);
		if (philo->fin > 0)
			philo->fin--;
		pthread_mutex_unlock(&philo->fmutex);
		return (-1);
	}
}
