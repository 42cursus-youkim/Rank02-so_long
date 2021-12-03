/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:07:19 by youkim            #+#    #+#             */
/*   Updated: 2021/12/03 13:36:29 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	manhattan(t_map *map, t_vec *epos, t_vec d)
{
	t_vec	newepos;

	vec_assign(&newepos, epos);
	vec_update(&newepos, d.x, d.y);
	if (is_there(map, &newepos, WALL) || is_there_enemy(map, &newepos))
		return (false);
	vec_assign(epos, &newepos);
	return (true);
}

void	try_move_manhattan(t_map *map, t_vec *epos, t_vec d)
{
	if (yrand() % 2)
	{
		if ((d.x && manhattan(map, epos, (t_vec){d.x, 0}))
			|| (d.y && manhattan(map, epos, (t_vec){0, d.y})))
			return ;
	}
	else
	{
		if ((d.y && manhattan(map, epos, (t_vec){0, d.y}))
			|| (d.x && manhattan(map, epos, (t_vec){d.x, 0})))
			return ;
	}
}

void	try_enemy_act(t_engine *engine, t_vec *epos, t_map *map, bool do_act)
{
	t_vec	*ppos;

	ppos = &map->ppos;
	check_lose(engine, ppos, epos);
	if (do_act)
		try_move_manhattan(map, epos, (t_vec){
			normalized(ppos->x - epos->x), normalized(ppos->y - epos->y)});
	check_lose(engine, ppos, epos);
}
