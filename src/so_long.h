/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:12:23 by kglebows          #+#    #+#             */
/*   Updated: 2023/09/28 17:28:25 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <fcntl.h>

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
	int					code;
	int					P_num;
	int					E_num;
	int					C_num;
}						t_map;

int	line2map(char *str, t_map *map);

#endif
