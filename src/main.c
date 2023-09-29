/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:26:44 by kglebows          #+#    #+#             */
/*   Updated: 2023/09/29 19:09:27 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(t_map *map)
{
	int			i;

	i = 0;
	ft_printf("Map %dx%d :: C:%d E:%d.%d P:%d.%d\n", map->width, map->height, map->C_num, map->E_pos.x, map->E_pos.y, map->P_pos.x, map->P_pos.y);
	while (i < map->height)
	{
		ft_printf("%s", map->map[i]);
		i++;
	}
}

// Print the window width and height.
// static void ft_hook(void* param)
// {
// 	const mlx_t* mlx = param;

// 	ft_printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
// }

int	main(int argn, char *argc[])
{
	t_map		map;
	int			i;
	int			j;

	if (argn < 2)
		return (ft_error(-18));
	if (argn > 2)
		return (ft_error(-19));
	map.path = argc[1];
	if (ft_ini(&map)!= 0)
		return (2);
	print_map(&map);

	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mlx_t* mlx = mlx_init(TILE_SIZE * map.width, TILE_SIZE * map.height, "Pickpocket Imp", true);
	if (!mlx)
		return (ft_error(-20));

	
	mlx_texture_t *slot = mlx_load_png("./src/assets/Inventory_Slot.png");
	mlx_texture_t *border = mlx_load_png("./src/assets/Inventory_background.png");
	
	mlx_image_t* img_slot = mlx_texture_to_image(mlx, slot);
	mlx_image_t* img_border = mlx_texture_to_image(mlx, border);
	mlx_resize_image(img_slot, TILE_SIZE, TILE_SIZE);
	mlx_resize_image(img_border, TILE_SIZE, TILE_SIZE);
	i = 0;
	while (i < map.width)
	{
		j = 0;
		while (j < map.height)
		{
			if (i == map.width - 1 || j == map.height - 1 || i == 0 || j == 0)
			{
				if (!img_border || (mlx_image_to_window(mlx, img_border, i * TILE_SIZE, j * TILE_SIZE) < 0))
					return (ft_error(-21));
			}
			else
			{
				if (!img_slot || (mlx_image_to_window(mlx, img_slot, i * TILE_SIZE, j * TILE_SIZE) < 0))
					return (ft_error(-21));
			}
			j++;
		}
		i++;
	}

	mlx_texture_t *player = mlx_load_png("./src/assets/player.png");
	mlx_texture_t *exit = mlx_load_png("./src/assets/exit.png");
	mlx_texture_t *coin = mlx_load_png("./src/assets/coin.png");
	mlx_texture_t *wall = mlx_load_png("./src/assets/wall.png");
	
	mlx_image_t* img_player = mlx_texture_to_image(mlx, player);
	mlx_image_t* img_exit = mlx_texture_to_image(mlx, exit);
	mlx_image_t* img_coin = mlx_texture_to_image(mlx, coin);
	mlx_image_t* img_wall = mlx_texture_to_image(mlx, wall);
	mlx_resize_image(img_player, TILE_SIZE, TILE_SIZE);
	mlx_resize_image(img_exit, TILE_SIZE, TILE_SIZE);
	mlx_resize_image(img_coin, TILE_SIZE, TILE_SIZE);
	mlx_resize_image(img_wall, TILE_SIZE, TILE_SIZE);

	
	i = 0;
	while (i < map.width)
	{
		j = 0;
		while (j < map.height)
		{
			if (i == map.width - 1 || j == map.height - 1 || i == 0 || j == 0)
			{

			}
			else
			{
				if (map.map[j][i] == 'P')
				{
					if (!img_player || (mlx_image_to_window(mlx, img_player, i * TILE_SIZE, j * TILE_SIZE) < 0))
						return (ft_error(-21));
				}
				if (map.map[j][i] == 'E')
				{
					if (!img_exit || (mlx_image_to_window(mlx, img_exit, i * TILE_SIZE, j * TILE_SIZE) < 0))
						return (ft_error(-21));
				}
				if (map.map[j][i] == 'C')
				{
					if (!img_coin || (mlx_image_to_window(mlx, img_coin, i * TILE_SIZE, j * TILE_SIZE) < 0))
						return (ft_error(-21));
				}
				if (map.map[j][i] == '1')
				{
					if (!img_wall || (mlx_image_to_window(mlx, img_wall, i * TILE_SIZE, j * TILE_SIZE) < 0))
						return (ft_error(-21));
				}
			}
			j++;
		}
		i++;
	}

	// Even after the image is being displayed, we can still modify the buffer.
	// mlx_put_pixel(img, 0, 0, 0xFF0000FF);

	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	// mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	// mlx_terminate(mlx);

	
	return (0);
}
