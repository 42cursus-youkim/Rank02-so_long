/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:05:13 by youkim            #+#    #+#             */
/*   Updated: 2021/12/01 21:38:43 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_frame(t_info *info)
{
	info->frames++;
	if (info->frames > FRAME_CYCLE)
		info->frames = 0;
}

//	check if the tile the entity's trying to go is smthn
bool	is_there(t_map *map, t_vec *pos, char thing)
{
	return (map->grid[pos->y][pos->x] == thing);
}

void	walk_anim(t_engine *engine)
{
	engine->info.otherwalk = !engine->info.otherwalk;
}

void	handle_walks(t_info *info)
{
	char	*log;
	char	*walks;

	info->walks++;
	walks = new_yitoa(info->walks);
	log = new_ystrjoin((char *[]){"\rwalks: ", walks, NULL});
	ywritecolor(1, log, HMAG);
	del_ystrs((char *[]){log, walks, NULL});
}
