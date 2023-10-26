/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:47:20 by kglebows          #+#    #+#             */
/*   Updated: 2023/10/26 15:15:14 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_position ft_pos(int x, int y)
{
    t_position pos;

    pos.x = x;
    pos.y = y;
    return (pos);    
}

t_position ft_pos_add(t_position org, t_position mov)
{
    t_position pos;

    pos.x = org.x + mov.x;
    pos.y = org.y + mov.y;
    return (pos);
}

t_position ft_pos_dist(t_position org, t_position mov)
{
    t_position pos;

    pos.x = org.x - mov.x;
    pos.y = org.y - mov.y;
    return (pos);
}