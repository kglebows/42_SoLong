/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 19:03:45 by kglebows          #+#    #+#             */
/*   Updated: 2023/11/07 13:31:18 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_tile(int x, int y, char *path, t_map *map)
{
	mlx_texture_t			*png;
	mlx_image_t				*img;

	png = mlx_load_png(path);
	img = mlx_texture_to_image(map->mlx, png);
	mlx_delete_texture(png);
	if (!img)
		ft_error(-21, map);
	mlx_resize_image(img, TILE_SIZE, TILE_SIZE);
	if (mlx_image_to_window(map->mlx, img, x * TILE_SIZE, y * TILE_SIZE) < 0)
		ft_error(-22, map);
}

char	*r_path(unsigned int random)
{
	char	*nbr;
	char	*ret;

	if (random < 100 && random > 9)
		nbr = ft_strjoin("0", ft_itoa(random));
	else if (random < 10)
		nbr = ft_strjoin("00", ft_itoa(random));
	else
		nbr = ft_itoa(random);
	ret = ft_strjoin(nbr, ".png");
	free(nbr);
	return (ret);
}

void	ft_put_wall(int x, int y, t_map *map)
{
	mlx_texture_t			*png;
	mlx_image_t				*img;
	char					*path;
	char					*random_path;

	random_path = r_path(ft_random(0, 500));
	path = ft_strjoin("./src/assets/wall/tile", random_path);
	free(random_path);
	png = mlx_load_png(path);
	free(path);
	img = mlx_texture_to_image(map->mlx, png);
	mlx_delete_texture(png);
	if (!img)
		ft_error(-21, map);
	mlx_resize_image(img, TILE_SIZE * 0.75, TILE_SIZE * 0.75);
	if (mlx_image_to_window(map->mlx, img, (x * TILE_SIZE) + TILE_SIZE * 0.125, (y * TILE_SIZE) + TILE_SIZE * 0.125) < 0)
		ft_error(-22, map);
}

mlx_image_t	*ft_put_coin(int x, int y, t_map *map)
{
	mlx_texture_t			*png;
	char					*path;
	char					*random_path;
	mlx_image_t				*img;

	random_path = r_path(map->frame % 6);
	path = ft_strjoin("./src/assets/coin/tile", random_path);
	free(random_path);
	png = mlx_load_png(path);
	free(path);
	img = mlx_texture_to_image(map->mlx, png);
	mlx_delete_texture(png);
	if (!img)
		ft_error(-21, map);
	mlx_resize_image(img, TILE_SIZE * 0.50, TILE_SIZE * 0.50);
	if (mlx_image_to_window(map->mlx, img, (x * TILE_SIZE) + TILE_SIZE * 0.25, (y * TILE_SIZE) + TILE_SIZE * 0.25) < 0)
		ft_error(-22, map);
	
	if (map->after_img[x][y])
		mlx_delete_image(map->mlx, map->after_img[x][y]);
	
	// map->after_img[x][y] = map->img_map[x][y];
	
	// map->img_map[x][y] = map->after_img[x][y];
	return (img);
}

mlx_image_t	*ft_put_imp(t_map *map)
{
	mlx_texture_t			*png;
	char					*path;
	char					*random_path;
	mlx_image_t				*img;

	if (map->jiggle != 0)
	{
		random_path = r_path(map->frame % 8 + 7);
		map->jiggle--;
	}
	else if (map->no != 0)
	{
		random_path = r_path(map->frame % 7 + 2);
		map->no--;
	}
	else if (map->frame < 90)
		random_path = r_path(map->frame % 7);
	else
		random_path = r_path(0);
	path = ft_strjoin("./src/assets/imp/tile", random_path);
	free(random_path);
	png = mlx_load_png(path);
	free(path);
	img = mlx_texture_to_image(map->mlx, png);
	mlx_delete_texture(png);
	if (!img)
		ft_error(-21, map);
	mlx_resize_image(img, TILE_SIZE * 0.75, TILE_SIZE * 0.75);
	if (mlx_image_to_window(map->mlx, img, (map->P_pos.x * TILE_SIZE) + TILE_SIZE * 0.125, (map->P_pos.y * TILE_SIZE) + TILE_SIZE * 0.3) < 0)
		ft_error(-22, map);
	// map->after_img[0][0] = map->img_map[0][0];

	if (map->after_img[map->P_pos.x][map->P_pos.y])
		mlx_delete_image(map->mlx, map->after_img[map->P_pos.x][map->P_pos.y]);
		
	return (img);
}

void	ft_put_enemy(t_map *map)
{
	mlx_texture_t			*png;

	if (map->img_map[0][1] != NULL)
		mlx_delete_image(map->mlx, map->img_map[0][1]);
	png = mlx_load_png("./src/assets/enemy.png");
	map->img_map[0][1] = mlx_texture_to_image(map->mlx, png);
	// mlx_delete_texture(png);
	if (!map->img_map[0][1])
		ft_error(-21, map);
	mlx_resize_image(map->img_map[0][1], TILE_SIZE * 1, TILE_SIZE * 1);
	if (mlx_image_to_window(map->mlx, map->img_map[0][1], (map->E_pos.x * TILE_SIZE) + TILE_SIZE * 0, (map->E_pos.y * TILE_SIZE) + TILE_SIZE * 0) < 0)
		ft_error(-22, map);
	// map->after_img[0][1] = map->img_map[0][1];
}

mlx_image_t	*ft_put_exit(int x, int y, t_map *map)
{
	mlx_texture_t			*png;
	char					*path;
	char					*random_path;
	mlx_image_t				*img;

	if (map->C_num != 0)
		random_path = r_path(map->frame % 4);
	else
		random_path = r_path(map->frame % 4 + 4);
	path = ft_strjoin("./src/assets/exit/tile", random_path);
	free(random_path);
	png = mlx_load_png(path);
	free(path);
	img = mlx_texture_to_image(map->mlx, png);
	mlx_delete_texture(png);
	if (!img)
		ft_error(-21, map);
	mlx_resize_image(img, TILE_SIZE * 0.75, TILE_SIZE * 0.75);
	if (mlx_image_to_window(map->mlx, img, (x * TILE_SIZE) + TILE_SIZE * 0.125, (y * TILE_SIZE) + TILE_SIZE * 0.375) < 0)
		ft_error(-22, map);
	// map->after_img[x][y] = map->img_map[x][y];
	return (img);
}

void put_string_steps(t_map *map)
{
	char		*str[2];

	mlx_delete_image(map->mlx, map->img_map[0][3]);
	str[0] = ft_itoa(map->steps);
	str[1] = ft_strjoin(" ->", str[0]);
	free(str[0]);
	map->img_map[0][3] = mlx_put_string(map->mlx, str[1], 0, (map->height - 0.5) * TILE_SIZE);
	free(str[1]);
}

void ft_put_string_inventory(t_map *map)
{
	char		*str[3];

	put_string_steps(map);
	mlx_delete_image(map->mlx, map->img_map[0][2]);
	str[0] = ft_itoa(map->C_num + map->W_num - map->height * 2 - (map->width - 2) * 2);
	str[1] = ft_itoa((map->width - 1) * (map->height - 1));
	str[2] = ft_strjoin("Inv : ", str[0]);
	free(str[0]);
	str[0] = ft_strjoin("/", str[1]);
	free(str[1]);
	str[1] = ft_strjoin(str[2], str[0]);
	free(str[2]);
	free(str[0]);
	map->img_map[0][2] = mlx_put_string(map->mlx, str[1], (map->width - 2) * TILE_SIZE, (map->height - 0.5) * TILE_SIZE);
	free(str[1]);
}

void ft_put_string(char *str, t_map *map)
{
	if (map->img_map[2][0])
		mlx_delete_image(map->mlx, map->img_map[2][0]);
	map->img_map[2][0] = mlx_put_string(map->mlx, str, (map->width - 3) / 2 * TILE_SIZE, 0.15 * TILE_SIZE);
}
