/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:21:44 by kglebows          #+#    #+#             */
/*   Updated: 2023/11/07 14:23:08 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

mlx_image_t *ft_load_image(unsigned int j, char *str, t_map *map)
{
	char					*path;
	char					*path_number;
	mlx_texture_t			*png;
	mlx_image_t				*img;

	path_number = r_path(j);
	path = ft_strjoin(str, path_number);
	free(path_number);
	png = mlx_load_png(path);
	free(path);
	img = mlx_texture_to_image(map->mlx, png);
	mlx_delete_texture(png);
	if (!img)
		ft_error(-21, map);
	return (img);
}