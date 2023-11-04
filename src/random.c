/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 09:38:58 by kglebows          #+#    #+#             */
/*   Updated: 2023/11/04 16:56:40 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

unsigned int seed(void)
{
	unsigned int	seed;

	seed = rand();
	return (seed);
}

unsigned int	ft_random(unsigned int min, unsigned int max)
{
	unsigned int		random;
	unsigned int		tmp;

	random = seed();
	if (max == min)
		return (0);
	if (min > max)
	{
		tmp = max;
		max = min;
		min = tmp;
	}
	random = (random % (max - min + 1)) + min;
	return (random);
}
