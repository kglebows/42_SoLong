/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 19:03:45 by kglebows          #+#    #+#             */
/*   Updated: 2023/11/09 13:36:16 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t	**ft_put_coin(int x, int y, t_map *map)
{
	mlx_image_t				**img;
	unsigned int			j;

	img = map->img_map[y][x];
	j = 0;
	while (j < 6)
	{
		img[j] = ft_load_image(j, "./src/assets/coin/tile", map);
		mlx_resize_image(img[j], TILE_SIZE * 0.50, TILE_SIZE * 0.50);
		if (mlx_image_to_window(map->mlx, img[j],
				(x * TILE_SIZE) + TILE_SIZE * 0.25,
				(y * TILE_SIZE) + TILE_SIZE * 0.25) < 0)
			ft_error(-22, map);
		img[j]->enabled = 0;
		j++;
	}
	return (img);
}

mlx_image_t	**ft_put_imp(t_map *map)
{
	mlx_image_t				**img;
	unsigned int			j;

	img = map->img_map[0][0];
	j = 0;
	while (j < 14)
	{
		img[j] = ft_load_image(j, "./src/assets/imp/tile", map);
		mlx_resize_image(img[j], TILE_SIZE * 0.75, TILE_SIZE * 0.75);
		if (mlx_image_to_window(map->mlx, img[j],
				(map->p_pos.x * TILE_SIZE) + TILE_SIZE * 0.125,
				(map->p_pos.y * TILE_SIZE) + TILE_SIZE * 0.3) < 0)
			ft_error(-22, map);
		img[j]->enabled = 0;
		j++;
	}
	return (img);
}

mlx_image_t	**ft_put_exit(int x, int y, t_map *map)
{
	mlx_image_t				**img;
	unsigned int			j;

	img = map->img_map[y][x];
	j = 0;
	while (j < 8)
	{
		img[j] = ft_load_image(j, "./src/assets/exit/tile", map);
		mlx_resize_image(img[j], TILE_SIZE * 0.75, TILE_SIZE * 0.75);
		if (mlx_image_to_window(map->mlx, img[j],
				(x * TILE_SIZE) + TILE_SIZE * 0.125,
				(y * TILE_SIZE) + TILE_SIZE * 0.375) < 0)
			ft_error(-22, map);
		img[j]->enabled = 0;
		j++;
	}
	return (img);
}

void	ft_put_enemy(t_map *map)
{
	mlx_texture_t			*png;

	if (map->difficulty == 0)
		png = mlx_load_png("./src/assets/enemy/tile000.png");
	else
		png = mlx_load_png("./src/assets/enemy/tile001.png");
	map->wall_map[0][0] = mlx_texture_to_image(map->mlx, png);
	mlx_delete_texture(png);
	if (!map->wall_map[0][0])
		ft_error(-21, map);
	mlx_resize_image(map->wall_map[0][0], TILE_SIZE * 1, TILE_SIZE * 1);
	if (mlx_image_to_window(map->mlx, map->wall_map[0][0],
		(map->e_pos.x * TILE_SIZE) + TILE_SIZE * 0,
		(map->e_pos.y * TILE_SIZE) + TILE_SIZE * 0) < 0)
		ft_error(-22, map);
	map->wall_map[0][0]->enabled = 0;
}
