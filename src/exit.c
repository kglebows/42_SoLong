/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:06:09 by kglebows          #+#    #+#             */
/*   Updated: 2023/11/07 18:22:38 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_2D_map(mlx_image_t ***img, t_map *map)
{
	int			i;

	if (img != NULL)
	{
		i = 0;
		while (i < map->height)
		{
			if (img[i] != NULL)
				free(img[i]);
			i++; 
		}
		free(img);
	}
}

void	clean_map(t_map *map)
{
	int			i;

	if (map->fd != 0)
		close(map->fd);
	if (map->map != NULL)
	{
		i = 0;
		while (i < map->height)
		{
			if (map->map[i] != NULL)
				free(map->map[i]);
			i++; 
		}
		free(map->map);
	}
	clean_2D_map(map->background_map, map);
	clean_2D_map(map->wall_map, map);
}

void	clean_img_map(t_map *map)
{
	int			i;
	int			j;

	if (map->img_map != NULL)
	{
		i = 0;
		while (i < map->height)
		{
			if (map->img_map[i] != NULL)
			{
				j = 0;
				while (j < map->width)
				{
					if (map->img_map[i][j] != NULL)
						free(map->img_map[i][j]);
					j++;
				}
				free(map->img_map[i]);
			}
			i++; 
		}
		free(map->img_map);
	}
}

void	clean_mlx(t_map *map)
{
	if (map->mlx)
	{
		if (map->mlx->window)
			mlx_close_window(map->mlx);
		mlx_terminate(map->mlx);	
	}
}

void	ft_exit(t_map *map)
{
	clean_map(map);
	clean_img_map(map);
	clean_mlx(map);
	exit(0);
}
