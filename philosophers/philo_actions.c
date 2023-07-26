/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_actions.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/09 14:23:10 by lizhang       #+#    #+#                 */
/*   Updated: 2022/10/29 16:12:30 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	unlock(t_philo *philo)
{
	if (accessd(philo->group, 0) == 0 || checkfinish(philo->group) > 0)
	{
		pthread_mutex_unlock(&philo->group->chops[philo->chop1]);
		pthread_mutex_unlock(&philo->group->chops[philo->chop2]);
		return (1);
	}
	else
		return (-1);
}

void	lonely(t_philo *philo)
{
	int	i;

	i = 0;
	if (accessd(philo->group, 0) == 1 && \
	checkfinish(philo->group) < 0 && i < 2)
	{
		pthread_mutex_lock(&philo->group->chops[philo->chop1]);
		printf("%lld: philosopher %d has taken a fork\n", \
		gettime(philo->group->time0), philo->id);
	}
	while (accessd(philo->group, 0) == 1 && \
	checkfinish(philo->group) < 0 && i < 2)
		usleep(500);
	pthread_mutex_unlock(&philo->group->chops[philo->chop1]);
	return ;
}

void	eating(t_philo *philo)
{
	long long	ct;
	int			i;

	i = 0;
	while (accessd(philo->group, 0) == 1 && \
	checkfinish(philo->group) < 0 && i < 2)
	{
		pthread_mutex_lock(&philo->group->chops[(philo->chop1 + \
		i) % philo->group->n]);
		if (accessd(philo->group, 0) == 1 && \
		checkfinish(philo->group) < 0 && i < 2)
			printf("%lld: philosopher %d has taken a fork\n", \
		gettime(philo->group->time0), philo->id);
		i++;
	}
	if (unlock(philo) == 1)
		return ;
	ct = gettime(philo->group->time0);
	accessmeal(philo, 1, ct);
	philo->state = 1;
	printf("%lld: philosopher %d is eating\n", ct, philo->id);
	stepsleep(philo->group->tte);
	pthread_mutex_unlock(&philo->group->chops[philo->chop1]);
	pthread_mutex_unlock(&philo->group->chops[philo->chop2]);
	accessf(philo, 1);
}

void	sleeping(t_philo *philo)
{
	long long	stime;

	stime = 0;
	printf("%lld: philosopher %d is sleeping\n", \
	gettime(philo->group->time0), philo->id);
	philo->state = 2;
	stepsleep(philo->group->tts);
}

void	thinking(t_philo *philo)
{
	printf("%lld: philosopher %d is thinking\n", \
	gettime(philo->group->time0), philo->id);
	philo->state = 3;
}
