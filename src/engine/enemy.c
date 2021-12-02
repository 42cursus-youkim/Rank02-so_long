/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:07:19 by youkim            #+#    #+#             */
/*   Updated: 2021/12/02 11:12:07 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	try_move_manhattan(t_map *map, t_vec *epos, int dx, int dy)
{
	t_vec	newepos;

	if (dx)
	{
		vec_assign(&newepos, epos);
		vec_update(&newepos, dx, 0);
		if (!is_there(map, &newepos, WALL))
			return (vec_assign(epos, &newepos));
	}
	if (dy)
	{
		vec_assign(&newepos, epos);
		vec_update(&newepos, 0, dy);
		if (!is_there(map, &newepos, WALL))
			return (vec_assign(epos, &newepos));
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
