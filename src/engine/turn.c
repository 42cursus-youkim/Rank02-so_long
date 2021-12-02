/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 09:59:23 by youkim            #+#    #+#             */
/*   Updated: 2021/12/02 12:36:32 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_win(t_engine *engine, t_vec *pos)
{
	if (engine->map->disks == 0 && is_there(engine->map, pos, EXIT))
	{
		printf("\n%sYou've won!%s\n", HGRN, END);
		engine->info.end = true;
	}
}

void	check_lose(t_engine *engine, t_vec *pos, t_vec *epos)
{
	if (pos->x == epos->x && pos->y == epos->y)
	{
		if (!engine->info.end)
			printf("\n%sYou've lost!%s\n", HRED, END);
		engine->info.end = true;
	}
}

void	enemies_turn(t_engine *engine, t_map *map, t_info *info)
{
	int	id;

	id = -1;
	info->otherturn = !info->otherturn;
	while (map->enemylst[++id])
		try_enemy_act(engine, map->enemylst[id], map, !info->otherturn);
}

void	take_turn(t_engine *engine, int dx, int dy)
{
	t_vec	newpos;
	t_vec	*ppos;

	ppos = &engine->map->ppos;
	vec_set(&newpos, ppos->x + dx, ppos->y + dy);
	if ((dx || dy) && is_there(engine->map, &newpos, WALL))
		return ;
	vec_assign(ppos, &newpos);
	check_win(engine, &newpos);
	enemies_turn(engine, engine->map, &engine->info);
	try_collect_disk(engine->map, &newpos);
	// log_walk(&engine->info);
	engine->info.walks++;
}
