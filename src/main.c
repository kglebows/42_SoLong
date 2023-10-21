/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:26:44 by kglebows          #+#    #+#             */
/*   Updated: 2023/10/21 15:18:42 by kglebows         ###   ########.fr       */
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

void	free_map(t_map *map)
{
	int				i;
	int				j;


	i = 1;
	while (i < map->width - 1)
	{
		j = 1;
		while (j < map->height - 1)
		{
			if (map->after_img[i][j] != NULL)
				mlx_delete_image(map->mlx, map->after_img[i][j]);
			j++;
		}
		i++;
	}
}

void	frame_map(t_map *map)
{
	int				i;
	int				j;

	// free_map(map);
	i = 1;
	while (i < map->width - 1)
	{
		j = 1;
		while (j < map->height - 1)
		{
			if (map->map[j][i] == 'P')
				map->img_map[i][j] = ft_put_imp(i, j, map);
			else if (map->map[j][i] == 'E')
				map->img_map[i][j] = ft_put_exit(i, j, map);
			else if (map->map[j][i] == 'C')
				map->img_map[i][j] = ft_put_coin(i, j, map);
			j++;
		}
		i++;
	}
}


void	ft_frame(void *param)
{
	t_map	*map;

	map = (t_map *) param;
	if (map->time < 903)
		map->time++;
	else
		map->time = 0;
	if (map->time % 10 == 2)
		free_map(map);
	if (map->time % 10 == 0)
	{
		map->frame++;
		if (map->frame > 12)
			map->frame = 0;
		frame_map(map);
		// ft_printf("%d FRAME\n", map->frame);
		
	}
	// ft_printf("%d\n", map->mlx->delta_time);
	// free_map(map);
}

int	main(int argn, char *argc[])
{
	t_map		map;

	if (argn < 2)
		return (ft_error(-18));
	if (argn > 2)
		return (ft_error(-19));
	map.path = argc[1];
	if (ft_ini(&map)!= 0)
		return (2);
	print_map(&map);

	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	map.mlx = mlx_init(TILE_SIZE * map.width, TILE_SIZE * map.height, "Pickpocket Imp", true);
	if (!map.mlx)
		return (ft_error(-20));
	ft_background(&map);
	
	// mlx_texture_t *player = mlx_load_png("./src/assets/player.png");
	// mlx_texture_t *exit = mlx_load_png("./src/assets/exit.png");
	// mlx_texture_t *coin = mlx_load_png("./src/assets/coin.png");
	// mlx_texture_t *wall = mlx_load_png("./src/assets/wall.png");
	
	// mlx_image_t* img_player = mlx_texture_to_image(map.mlx, player);
	// mlx_image_t* img_exit = mlx_texture_to_image(map.mlx, exit);
	// mlx_image_t* img_coin = mlx_texture_to_image(map.mlx, coin);
	// mlx_image_t* img_wall = mlx_texture_to_image(map.mlx, wall);
	// mlx_resize_image(img_player, TILE_SIZE, TILE_SIZE);
	// mlx_resize_image(img_exit, TILE_SIZE, TILE_SIZE);
	// mlx_resize_image(img_coin, TILE_SIZE, TILE_SIZE);
	// mlx_resize_image(img_wall, TILE_SIZE, TILE_SIZE);

	
	

	// Even after the image is being displayed, we can still modify the buffer.
	// mlx_put_pixel(img, 0, 0, 0xFF0000FF);

	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	// mlx_loop_hook(mlx, ft_hook, mlx);
	map.frame = 0;
	map.time = 0;
	mlx_loop_hook(map.mlx, ft_frame, &map);
	mlx_loop(map.mlx);
	// mlx_terminate(mlx);

	
	return (0);
}
