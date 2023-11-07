/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:26:44 by kglebows          #+#    #+#             */
/*   Updated: 2023/11/07 20:17:49 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void my_keyhook(mlx_key_data_t keydata, void *ptr)
{
	t_map	*map;

	map = ptr;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		ft_exit(map);
	if (map->endgame != 1)
	{
		if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
			ft_move(ft_pos_add(map->P_pos, ft_pos(0,-1)), map);
		else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
			ft_move(ft_pos_add(map->P_pos, ft_pos(-1,0)), map);
		else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
			ft_move(ft_pos_add(map->P_pos, ft_pos(0,1)), map);
		else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
			ft_move(ft_pos_add(map->P_pos, ft_pos(1,0)), map);
	}
	else
	{
		if (keydata.key == MLX_KEY_L && keydata.action == MLX_PRESS)
			ft_restart_map(map);
		else if (keydata.key == MLX_KEY_E && keydata.action == MLX_PRESS)
			ft_exit(map);
	}
}

void load_img_map(t_map *map)
{
	int					x;
	int					y;
	mlx_image_t			****img;

	img = map->img_map;
	img[0][0] = ft_put_imp(map);
	ft_put_enemy(map);
	x = 1;
	while (x < map->width - 1)
	{
		y = 1;
		while (y < map->height - 1)
		{
 			if (map->map[y][x] == 'E')
				img[y][x] = ft_put_exit(x, y, map);
			else if (map->map[y][x] == 'C')
				img[y][x] = ft_put_coin(x, y, map);
			y++;
		}
		x++;
	}
}

void	initial_values(char *str, t_map *map)
{
	map->difficulty = 99;
	map->path = str;
	map->background_map = NULL;
	map->wall_map = NULL;
	map->img_map = NULL;
	map->map = NULL;
	map->mlx = NULL;
	map->width = 0;
	map->height = 0;
	map->C_num = 0;
	map->E_num = 0;
	map->P_num = 0;
	map->W_num = 0;
	map->jiggle = 0;
	map->no = 100;
	map->E_pos = ft_pos(1, 1);
	map->level = 0;
	map->endgame = 0;
	map->steps = 0;
	map->time = 0;
}

int main(int argn, char *argc[])
{
	t_map map;

	initial_values(argc[1], &map);
	if (argn < 2)
		ft_error(-18, &map);
	if (argn > 2)
		ft_error(-19, &map);
	ft_ini(&map);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	map.mlx = mlx_init(TILE_SIZE * map.width, TILE_SIZE * map.height,
			"Inventory Imp", true);
	if (!map.mlx)
		ft_error(-20, &map);
	ft_background(&map);
	load_img_map(&map);
	ft_put_string_inventory(&map);
	ft_put_string("    GET COINS!!!", &map);
	mlx_key_hook(map.mlx, &my_keyhook, &map);
	mlx_loop_hook(map.mlx, ft_frame, &map);
	mlx_loop(map.mlx);
	ft_exit(&map);
	return (0);
}

