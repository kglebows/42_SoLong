/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:12:23 by kglebows          #+#    #+#             */
/*   Updated: 2023/10/20 20:59:13 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <fcntl.h>
# include "lib/MLX42/include/MLX42/MLX42.h"


#define TILE_SIZE 64


typedef struct s_position
{
	int					x;
	int					y;
}						t_position;

typedef struct s_map
{
	int					height;
	int					width;
	char				**map;
	char				*path;
	int					fd;
	int					P_num;
	int					E_num;
	int					C_num;
	t_position			P_pos;
	t_position			E_pos;
	mlx_t				*mlx;
}						t_map;

int			ft_error(int code);
int			ft_ini(t_map *map);
int			ft_map(t_map *map);
t_position	ft_find_element(char **cpy, char c, t_map *map);

int	ft_put_tile(int x, int y, char *path, t_map *map);
int	ft_put_wall(int x, int y, char *path, t_map *map);

#endif
