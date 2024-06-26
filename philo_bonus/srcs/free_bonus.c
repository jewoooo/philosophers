/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 23:21:34 by jewlee            #+#    #+#             */
/*   Updated: 2024/06/10 12:16:14 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	unlink_free(t_philo **philo)
{
	sem_close((*philo)->forks_sem);
	sem_close((*philo)->print_sem);
	sem_unlink("/forks_sem");
	sem_unlink("/print_sem");
	free((*philo)->pid);
	free(*philo);
}
