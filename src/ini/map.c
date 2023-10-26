/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:30:06 by kglebows          #+#    #+#             */
/*   Updated: 2023/09/29 14:43:19 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood(int y, int x, char **cpy)
{
	if (cpy[y][x] != '1' && cpy[y][x] != 'F')
	{
		cpy[y][x] = 'F';
		flood(y + 1, x, cpy);
		flood(y - 1, x, cpy);
		flood(y, x + 1, cpy);
		flood(y, x - 1, cpy);
	}
}

void	map_flood(char **cpy, t_map *map)
{
	t_position			pos;

	pos.y = 0;
	while (pos.y < map->height)
	{
		pos.x = 0;
		while (pos.x < map->width)
		{
			if (cpy[pos.y][pos.x] == 'P')
				flood(pos.y, pos.x, cpy);
			pos.x++;
		}
		pos.y++;
	}
}

int	create_map(t_map *map)
{
	char		*str;
	int			i;

	i = 0;
	map->fd = open(map->path, 0);
	if (map->fd < 1)
		return (ft_error(-8));
	map->map = (char **) calloc(map->height, sizeof(char *));
	if (!map->map)
		return (ft_error(-12));
	while (i < map->height)
	{
		str = get_next_line(map->fd);
		map->map[i] = str;
		i++;
	}
	i = 0;
	while (i < map->width)
	{
		if (str[i] != '1')
			return (ft_error(-13));
		i++;
	}
	close(map->fd);
	return (0);
}

int	ft_map(t_map *map)
{
	char		**cpy;
	int			i;

	if (create_map(map) != 0)
		return (2);
	cpy = (char **) calloc(map->height, sizeof(char *));
	if (!cpy)
		return (ft_error(-16));
	i = 0;
	while (i < map->height)
	{
		cpy[i] = ft_strdup(map->map[i]);
		i++;
	}
	map_flood(cpy, map);
	if (ft_find_element(cpy, 'C', map).x != -1)
		return (ft_error(-17));
	map->P_pos = ft_find_element(map->map, 'P', map);
	map->E_pos = ft_find_element(map->map, 'E', map);
	while (i-- > 0)
		free(cpy[i]);
	free(cpy);
	i = 0;
	return (0);
}
