/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:40:21 by kglebows          #+#    #+#             */
/*   Updated: 2023/11/09 13:31:12 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_position	ft_find_element(char **cpy, char c, t_map *map)
{
	t_position		pos;

	pos.x = 0;
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

void	ft_image_map(t_map *map)
{
	int				i;
	int				j;

	map->img_map = (mlx_image_t ****) ft_calloc(map->height,
			sizeof(mlx_image_t ***));
	if (!map->img_map)
		ft_error(-12, map);
	i = 0;
	while (i < map->height)
	{
		map->img_map[i] = (mlx_image_t ***) ft_calloc(map->width,
				sizeof(mlx_image_t **));
		if (!map->img_map[i])
			ft_error(-12, map);
		j = 0;
		while (j < map->width)
		{
			map->img_map[i][j] = (mlx_image_t **) ft_calloc(16,
					sizeof(mlx_image_t *));
			if (!map->img_map[i][j])
				ft_error(-12, map);
			j++;
		}
		i++;
	}
}

void	wall_map(t_map *map)
{
	int				i;

	map->wall_map = (mlx_image_t ***) ft_calloc(map->height,
			sizeof(mlx_image_t **));
	if (!map->wall_map)
		ft_error(-12, map);
	i = 0;
	while (i < map->height)
	{
		map->wall_map[i] = (mlx_image_t **) ft_calloc(map->width,
				sizeof(mlx_image_t *));
		if (!map->wall_map[i])
			ft_error(-12, map);
		i++;
	}
}

void	ft_background_map(t_map *map)
{
	int				i;

	map->background_map = (mlx_image_t ***) ft_calloc(map->height,
			sizeof(mlx_image_t **));
	if (!map->background_map)
		ft_error(-12, map);
	i = 0;
	while (i < map->height)
	{
		map->background_map[i] = (mlx_image_t **) ft_calloc(map->width,
				sizeof(mlx_image_t *));
		if (!map->background_map[i])
			ft_error(-12, map);
		i++;
	}
	wall_map(map);
}
