/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenc <egenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 09:24:43 by egenc             #+#    #+#             */
/*   Updated: 2023/04/26 09:25:12 by egenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*ft_check_death(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		sem_wait(philo->data->death);
		if (philo->next_meal < gettime())
		{
			ft_print_message(5, philo);
			sem_post(philo->data->stop);
			break ;
		}
		sem_post(philo->data->death);
		sem_wait(philo->data->death);
		if ((philo->data->eat_counter != -1)
			&& (philo->data->current_eat >= philo->data->max_eat))
		{
			sem_post(philo->data->stop);
			break ;
		}
		sem_post(philo->data->death);
	}
	return (NULL);
}
