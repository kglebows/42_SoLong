/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:12:23 by kglebows          #+#    #+#             */
/*   Updated: 2023/11/04 17:55:58 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <fcntl.h>
# include "lib/MLX42/include/MLX42/MLX42.h"
# include "math.h"


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
	mlx_image_t			***img_map;
	mlx_image_t			***after_img;
	char				*path;
	int					fd;
	int					P_num;
	int					E_num;
	int					C_num;
	int					W_num;
	int					jiggle;
	int					no;
	int					level;
	int					endgame;
	t_position			P_pos;
	t_position			E_pos;
	mlx_t				*mlx;
	unsigned int		frame;
	unsigned int		time;
	int					steps;
}						t_map;

void			ft_error(int code, t_map *map);
void			ft_ini(t_map *map);
void			ft_map(t_map *map);
t_position	ft_find_element(char **cpy, char c, t_map *map);
void			ft_image_map(t_map *map);

void	ft_background(t_map *map);

void	ft_put_tile(int x, int y, char *path, t_map *map);
void	ft_put_wall(int x, int y, t_map *map);
mlx_image_t	*ft_put_coin(int x, int y, t_map *map);
mlx_image_t	*ft_put_imp(t_map *map);
mlx_image_t	*ft_put_exit(int x, int y, t_map *map);
void		ft_put_enemy(t_map *map);
void ft_put_string_inventory(t_map *map);
void ft_put_string(char *str, t_map *map);

unsigned int	ft_random(unsigned int min, unsigned int max);

t_position ft_pos(int x, int y);
t_position ft_pos_add(t_position org, t_position mov);
t_position ft_pos_dist(t_position org, t_position mov);

void	ft_move(t_position pos, t_map *map);
void	ft_exit(t_map *map);
void	ft_move_enemy(t_map *map);

void ft_free_map(t_map *map);
void ft_restart_map(t_map *map);

void ft_frame(void *param);

#endif
