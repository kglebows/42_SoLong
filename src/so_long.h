/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:12:23 by kglebows          #+#    #+#             */
/*   Updated: 2023/11/09 13:19:44 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <fcntl.h>
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "math.h"

# define TILE_SIZE 64

typedef struct s_position
{
	int					x;
	int					y;
}						t_position;

typedef struct s_map
{
	mlx_t				*mlx;
	mlx_image_t			***background_map;
	mlx_image_t			***wall_map;
	mlx_image_t			****img_map;
	char				*path;
	char				**map;
	t_position			p_pos;
	t_position			e_pos;
	int					fd;
	int					no;
	int					p_num;
	int					e_num;
	int					c_num;
	int					w_num;
	int					level;
	int					steps;
	int					width;
	int					height;
	int					jiggle;
	int					endgame;
	int					difficulty;
	unsigned int		time;
}						t_map;

t_position		ft_find_element(char **cpy, char c, t_map *map);
t_position		ft_pos(int x, int y);
t_position		ft_pos_add(t_position org, t_position mov);
t_position		ft_pos_dist(t_position org, t_position mov);
mlx_image_t		*ft_load_image(unsigned int j, char *str, t_map *map);
mlx_image_t		**ft_put_coin(int x, int y, t_map *map);
mlx_image_t		**ft_put_imp(t_map *map);
mlx_image_t		**ft_put_exit(int x, int y, t_map *map);
unsigned int	ft_random(unsigned int min, unsigned int max);
void			ft_frame(void *param);
void			ft_error(int code, t_map *map);
void			ft_ini(t_map *map);
void			ft_map(t_map *map);
void			ft_image_map(t_map *map);
void			ft_background_map(t_map *map);
void			ft_background(t_map *map);
void			ft_levelup_enemy(t_map *map);
void			ft_put_enemy(t_map *map);
void			ft_put_string_inventory(t_map *map);
void			ft_put_string(char *str, t_map *map);
void			ft_animate(mlx_image_t **img, int maxf, int anim, t_map *map);
void			ft_move_pos(t_map *map);
void			ft_move(t_position pos, t_map *map);
void			ft_exit(t_map *map);
void			ft_move_enemy(t_map *map);
void			ft_restart_map(t_map *map);

#endif