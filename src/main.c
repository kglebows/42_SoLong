/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:26:44 by kglebows          #+#    #+#             */
/*   Updated: 2023/10/26 15:19:17 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void print_map(t_map *map)
{
	int i;

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
// 	const mlx_t* mlx = param; sad we are 

// 	ft_printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height); weel this is not ideal but it works 
// }

void free_map(t_map *map)
{
	int i;
	int j;

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

void frame_map(t_map *map)
{
	int i;
	int j;

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

void ft_frame(void *param)
{
	t_map *map;

	map = (t_map *)param;
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
	// ft_printf("%d\n"asd, map->mlx->delta_time);
	// free_map(map)d sfsd fdsf sggdgsdg sdfwe werwe wer; sdasd fasff wwww eee qwrsa asf qwa sadf qwe sdw qwerqsad qwe hjh gh hjghj fgfgt ddd
}

void my_keyhook(mlx_key_data_t keydata, void *ptr)
{

	t_map	*map;

	map = ptr;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
	{
		ft_printf("W%d", map->);
	}
		/*check element function -> takes player position + Key position value, checks a symbol above, if 
		1 - "imp dandle animation (frames inside jump)" 
		C - change to 0 and move player to this position. change number if c by -1
		0 - move player to this position
		P - move player to this postion
		E - move player to this position, if coin=0 - end game. else do imp dandle constantly.

dasdw dfdsew dsa
		i need to do position arythmetic
		functions:
		pos = pos(x,y)
		pos = add_pos(pos, pos)
		pos = dist_pos(pos, pos) - returns distance between two positions to calculate for enemy_frame

		i need to track player position and draw imp based on that
		P statrtign position of imp

		later for enemy it is gonna be usfull also moving function of the enemy_frame
		*/
	
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
	{
		ft_printf("A");
	}	
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
	{
		ft_printf("S");
	}	
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
	{
		ft_printf("D");
	}
		

}


int main(int argn, char *argc[])
{
	t_map map;

	if (argn < 2)
		return (ft_error(-18));
	if (argn > 2)
		return (ft_error(-19));
	map.path = argc[1];
	if (ft_ini(&map) != 0)
		return (2);
	print_map(&map);

	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	map.mlx = mlx_init(TILE_SIZE * map.width, TILE_SIZE * map.height, "Pickpocket Imp", true);
	if (!map.mlx)
		return (ft_error(-20));
	ft_background(&map);

	mlx_key_hook(map.mlx, &my_keyhook, &map);	

	map.frame = 0;
	map.time = 0;
	mlx_loop_hook(map.mlx, ft_frame, &map);
	mlx_loop(map.mlx);
	// mlx_terminae(mlx);sd fewd i i need to whit can sads w eae as i am dukced fsefr wa dwasd eee wa sdfe asdw write a bitd slow. one two three it works better now! what the duck why processor is goin apeshit  ssd wa s
	// i write code slow
	// how to write code eficient 
	// how to write codfsdde efficientdffsf dfsdf sdf wwww ees dsf w
	// foking heeel!! sdsdawe we  sw sdasd sdf wdddddddasdasdaswyerwerw dfsg qwedsarqw sadwieajksd ad qwegsd ssdwea sd ww eas weras ddd eq
// sadasd sdawe asdwa
	return (0);
}
