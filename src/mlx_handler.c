/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 19:03:45 by kglebows          #+#    #+#             */
/*   Updated: 2023/10/26 16:57:45 by kglebows         ###   ########.fr       */
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

int	ft_put_wall(int x, int y, t_map *map)
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
		return (ft_error(-21));
	mlx_resize_image(img, TILE_SIZE * 0.75, TILE_SIZE * 0.75);
	if (mlx_image_to_window(map->mlx, img, (x * TILE_SIZE) + TILE_SIZE * 0.125, (y * TILE_SIZE) + TILE_SIZE * 0.125) < 0)
		return (ft_error(-22));
	else
		return (0);
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
		return (ft_error(-21), NULL);
	mlx_resize_image(img, TILE_SIZE * 0.50, TILE_SIZE * 0.50);
	if (mlx_image_to_window(map->mlx, img, (x * TILE_SIZE) + TILE_SIZE * 0.25, (y * TILE_SIZE) + TILE_SIZE * 0.25) < 0)
		return (ft_error(-22), NULL);
	map->after_img[x][y] = map->img_map[x][y];
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
		// random_path = r_path(map->frame % 4 + 9);
		random_path = r_path(map->frame % 8 + 7);
		map->jiggle--;
	}
	else if (map->time < 90)
		random_path = r_path(map->frame % 7);
	// else if (map->time > 400 && map->time < 500)
	// 	random_path = r_path(map->frame % 8 + 7);
	else
		random_path = r_path(0);
	path = ft_strjoin("./src/assets/imp/tile", random_path);
	free(random_path);
	png = mlx_load_png(path);
	free(path);
	img = mlx_texture_to_image(map->mlx, png);
	mlx_delete_texture(png);
	if (!img)
		return (ft_error(-21), NULL);
	mlx_resize_image(img, TILE_SIZE * 0.75, TILE_SIZE * 0.75);
	if (mlx_image_to_window(map->mlx, img, (map->P_pos.x * TILE_SIZE) + TILE_SIZE * 0.125, (map->P_pos.y * TILE_SIZE) + TILE_SIZE * 0.3) < 0)
		return (ft_error(-22), NULL);
	map->after_img[0][0] = map->img_map[0][0];
	return (img);
}

mlx_image_t	*ft_put_enemy(t_map *map)
{
	mlx_texture_t			*png;
	mlx_image_t				*img;

	png = mlx_load_png("./src/assets/enemy.png");
	img = mlx_texture_to_image(map->mlx, png);
	mlx_delete_texture(png);
	if (!img)
		return (ft_error(-21), NULL);
	mlx_resize_image(img, TILE_SIZE * 1, TILE_SIZE * 1);
	if (mlx_image_to_window(map->mlx, img, (map->E_pos.x * TILE_SIZE) + TILE_SIZE * 0, (map->E_pos.y * TILE_SIZE) + TILE_SIZE * 0) < 0)
		return (ft_error(-22), NULL);
	return (img);
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
		return (ft_error(-21), NULL);
	mlx_resize_image(img, TILE_SIZE * 0.75, TILE_SIZE * 0.75);
	if (mlx_image_to_window(map->mlx, img, (x * TILE_SIZE) + TILE_SIZE * 0.125, (y * TILE_SIZE) + TILE_SIZE * 0.375) < 0)
		return (ft_error(-22), NULL);
	map->after_img[x][y] = map->img_map[x][y];
	return (img);
}
// mlx_image_t	*ft_put_coin(int x, int y, t_map *map)
// {
// 	mlx_texture_t			*png;
// 	char					*path;
// 	char					*random_path;
// 	mlx_image_t				*img;

// 	random_path = r_path(map->frame % 6);
// 	path = ft_strjoin("./src/assets/coin/tile", random_path);
// 	free(random_path);
// 	png = mlx_load_png(path);
// 	free(path);
// 	map->img_map[x][y] = mlx_texture_to_image(map->mlx, png);
// 	mlx_delete_texture(png);
// 	if (!map->img_map[x][y])
// 		return (ft_error(-21), NULL);
// 	mlx_resize_image(map->img_map[x][y], TILE_SIZE * 0.75, TILE_SIZE * 0.75);
// 	if (mlx_image_to_window(map->mlx, map->img_map[x][y], (x * TILE_SIZE) + TILE_SIZE * 0.125, (y * TILE_SIZE) + TILE_SIZE * 0.125) < 0)
// 		return (ft_error(-22), NULL);
// 	if (map->img_map[x][y] != NULL)
// 			mlx_delete_image(map->mlx, map->img_map[x][y]);
// 	return (map->img_map[x][y]);
// }