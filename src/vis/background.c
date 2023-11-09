/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 11:12:09 by kglebows          #+#    #+#             */
/*   Updated: 2023/11/09 13:33:36 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t	*ft_put_tile(int x, int y, unsigned int j, t_map *map)
{
	mlx_image_t				*img;

	img = ft_load_image(j, "./src/assets/bg/tile", map);
	mlx_resize_image(img, TILE_SIZE, TILE_SIZE);
	if (mlx_image_to_window(map->mlx, img, x * TILE_SIZE, y * TILE_SIZE) < 0)
		ft_error(-22, map);
	return (img);
}

mlx_image_t	*ft_put_wall(int x, int y, t_map *map)
{
	mlx_image_t				*img;

	img = ft_load_image(ft_random(0, 500), "./src/assets/wall/tile", map);
	mlx_resize_image(img, TILE_SIZE * 0.75, TILE_SIZE * 0.75);
	if (mlx_image_to_window(map->mlx, img, (x * TILE_SIZE)
			+ TILE_SIZE * 0.125, (y * TILE_SIZE) + TILE_SIZE * 0.125) < 0)
		ft_error(-22, map);
	return (img);
}

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
			map->background_map[j][i] = ft_put_tile(i, j, 9, map);
			if (map->map[j][i] == '1')
			{
				map->wall_map[j][i] = ft_put_wall(i, j, map);
			}
			j++;
		}
		i++;
	}
}

void	ft_background(t_map *map)
{
	int			i;
	int			j;

	i = map->width - 1;
	j = map->height - 1;
	map->background_map[0][0] = ft_put_tile(0, 0, 0, map);
	map->background_map[j][0] = ft_put_tile(0, j, 6, map);
	map->background_map[0][i] = ft_put_tile(i, 0, 2, map);
	map->background_map[j][i] = ft_put_tile(i, j, 8, map);
	i = 0;
	while (i++ < map->width - 2)
	{
		map->background_map[0][i] = ft_put_tile(i, 0, 1, map);
		map->background_map[j][i] = ft_put_tile(i, j, 7, map);
	}
	i = 0;
	j = map->width - 1;
	while (i++ < map->height - 2)
	{
		map->background_map[i][0] = ft_put_tile(0, i, 3, map);
		map->background_map[i][j] = ft_put_tile(j, i, 5, map);
	}
	background_(map);
}
