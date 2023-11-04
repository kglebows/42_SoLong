/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:06:09 by kglebows          #+#    #+#             */
/*   Updated: 2023/11/04 18:13:53 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_data(t_map *map)
{
	if (map->path)
		map->path = NULL;
	if (map->after_img)
		map->after_img = NULL;
	if (map->img_map)
		map->img_map = NULL;
	if (map->map)
		map->map = NULL;
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
			if (map->map[i])
				free(map->map[i]);
			i++; 
		}
		free(map->map);
	}
}

void	clean_img_map(t_map *map)
{
	int			i;

	if (map->img_map)
	{
		i = 0;
		while (i < map->height)
		{
			if (map->img_map[i])
				free(map->img_map[i]);
			i++; 
		}
		free(map->img_map);
	}
	if (map->after_img)
	{
		i = 0;
		while (i < map->height)
		{
			if (map->after_img[i])
				free(map->after_img[i]);
			i++; 
		}
		free(map->after_img);
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
	clean_data(map);
	clean_mlx(map);
	exit(0);
}