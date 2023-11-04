/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 11:12:09 by kglebows          #+#    #+#             */
/*   Updated: 2023/11/04 16:36:31 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	background_(t_map *map)
{
	int		i;
	int		j;

	i = 1;
	while (i < map->width - 1)
	{
		j = 1;
		while (j < map->height - 1)
		{
			ft_put_tile(i, j, "./src/assets/bg/slot.png", map);
			if (map->map[j][i] == '1')
			{
				ft_put_wall(i, j, map);
			}
			j++;
		}
		i++;
	}
}

void	ft_background(t_map *map)
{
	int			i;

	ft_put_tile(0, 0, "./src/assets/bg/tile000.png", map);
	ft_put_tile(0, map->height - 1, "./src/assets/bg/tile006.png", map);
	ft_put_tile(map->width - 1, 0, "./src/assets/bg/tile002.png", map);
	ft_put_tile(map->width - 1, map->height - 1, "./src/assets/bg/tile008.png",
				map);
	i = 0;
	while (i++ < map->width - 2)
	{
		ft_put_tile(i, 0, "./src/assets/bg/tile001.png", map);
		ft_put_tile(i, map->height - 1, "./src/assets/bg/tile007.png", map);
	}
	i = 0;
	while (i++ < map->height - 2)
	{
		ft_put_tile(0, i, "./src/assets/bg/tile003.png", map);
		ft_put_tile(map->width - 1, i, "./src/assets/bg/tile005.png", map);
	}
	background_(map);
}
