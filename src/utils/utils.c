/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:05:13 by youkim            #+#    #+#             */
/*   Updated: 2021/12/01 21:10:19 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_frame(t_info *info)
{
	info->frames++;
	if (info->frames > FRAME_CYCLE)
		info->frames = 0;
}

//	check if thee tile is a wall
bool	is_wall(t_map *map, t_vec *pos)
{
	return (map->grid[pos->y][pos->x] == WALL);
}
