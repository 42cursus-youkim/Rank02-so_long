/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:07:19 by youkim            #+#    #+#             */
/*   Updated: 2021/12/02 11:22:12 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	manhattan(t_map *map, t_vec *epos, int dx, int dy)
{
	t_vec	newepos;

	vec_assign(&newepos, epos);
	vec_update(&newepos, dx, dy);
	if (is_there(map, &newepos, WALL))
		return (false);
	vec_assign(epos, &newepos);
	return (true);
}

void	try_move_manhattan(t_map *map, t_vec *epos, int dx, int dy)
{
	if (rand() % 2)
	{
		if (dx && manhattan(map, epos, dx, 0))
			return ;
		if (dy && manhattan(map, epos, 0, dy))
			return ;
	}
	else
	{
		if (dy && manhattan(map, epos, 0, dy))
			return ;
		if (dx && manhattan(map, epos, dx, 0))
			return ;
	}
}

void	try_enemy_act(t_engine *engine, t_map *map, t_info *info)
{
	t_vec	*epos;
	t_vec	*ppos;

	epos = &map->epos;
	ppos = &map->ppos;
	check_lose(engine, ppos, epos);
	info->otherturn = !info->otherturn;
	if (info->otherturn)
		return ;
	try_move_manhattan(map, epos,
		normalized(ppos->x - epos->x), normalized(ppos->y - epos->y));
	check_lose(engine, ppos, epos);
}
