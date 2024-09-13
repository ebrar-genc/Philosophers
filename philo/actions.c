/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenc <egenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:52:08 by egenc             #+#    #+#             */
/*   Updated: 2023/01/08 12:58:23 by egenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philo *ph)
{
	gettime(ph);
	pthread_mutex_lock(ph->l_f);
	pthread_mutex_lock(ph->r_f);
	gettime(ph);
	pthread_mutex_lock(ph->lock);
	if (!*ph->is_ph_dead)
	{
		printf("%ld %d has taken a fork\n", ph->start_time, ph->id);
		printf("%ld %d has taken a fork\n", ph->start_time, ph->id);
	}
	pthread_mutex_unlock(ph->lock);
}

void	ft_think(t_philo *ph)
{
	gettime(ph);
	pthread_mutex_lock(ph->lock);
	if (!*ph->is_ph_dead)
		printf("%ld %d is thinking\n", ph->start_time, ph->id);
	pthread_mutex_unlock(ph->lock);
}

void	ft_sleep(t_philo *ph)
{
	gettime(ph);
	pthread_mutex_lock(ph->lock);
	if (!*ph->is_ph_dead)
		printf("%ld %d is sleeping\n", ph->start_time, ph->id);
	pthread_mutex_unlock(ph->lock);
	ft_usleep(ph, ph->time_to_eat);
}

void	eat(t_philo *ph)
{
	gettime(ph);
	pthread_mutex_lock(ph->lock);
	if (!*ph->is_ph_dead)
		printf("%ld %d is eating\n", ph->start_time, ph->id);
	pthread_mutex_unlock(ph->lock);
	ph->death = ph->start_time + ph->time_to_die;
	ph->hm_eat++;
	ft_usleep(ph, ph->time_to_eat);
	pthread_mutex_unlock(ph->r_f);
	pthread_mutex_unlock(ph->l_f);
}
