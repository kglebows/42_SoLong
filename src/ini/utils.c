/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:40:21 by kglebows          #+#    #+#             */
/*   Updated: 2023/09/29 14:40:35 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_position	ft_find_element(char **cpy, char c, t_map *map)
{
	t_position		pos;

	pos.y = 0;
	while (pos.y < map->height)
	{
		pos.x = 0;
		while (pos.x < map->width)
		{
			if (cpy[pos.y][pos.x] == c)
				return (pos);
			pos.x++;
		}
		pos.y++;
	}
	pos.x = -1;
	pos.y = -1;
	return (pos);
}
