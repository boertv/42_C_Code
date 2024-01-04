/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_behaviour.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:51:07 by bvercaem          #+#    #+#             */
/*   Updated: 2024/01/04 18:19:04 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*behaviour(void *input)
{
// stop if not all philos could be created (game_state?)
	t_philosopher	*guts;

	guts = input;
	printf("created nr: %i\n", guts->id);
	free(input);
	return (NULL);
}
