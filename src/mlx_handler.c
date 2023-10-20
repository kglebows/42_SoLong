/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 19:03:45 by kglebows          #+#    #+#             */
/*   Updated: 2023/10/20 20:58:58 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_put_tile(int x, int y, char *path, t_map *map)
{
	mlx_texture_t			*png;
	mlx_image_t				*img;

	png = mlx_load_png(path);
	img = mlx_texture_to_image(map->mlx, png);
	mlx_delete_texture(png);
	if (!img)
		return (ft_error(-21));
	mlx_resize_image(img, TILE_SIZE, TILE_SIZE);
	if (mlx_image_to_window(map->mlx, img, x * TILE_SIZE, y * TILE_SIZE) < 0)
		return (ft_error(-22));
	else
		return (0);
}

int	ft_put_wall(int x, int y, char *path, t_map *map)
{
	mlx_texture_t			*png;
	mlx_image_t				*img;

	png = mlx_load_png(path);
	img = mlx_texture_to_image(map->mlx, png);
	mlx_delete_texture(png);
	if (!img)
		return (ft_error(-21));
	mlx_resize_image(img, TILE_SIZE - 12, TILE_SIZE - 12);
	if (mlx_image_to_window(map->mlx, img, (x * TILE_SIZE) + 6, (y * TILE_SIZE) + 6) < 0)
		return (ft_error(-22));
	else
		return (0);
}