/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 09:59:23 by youkim            #+#    #+#             */
/*   Updated: 2021/12/03 12:50:12 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_win(t_engine *engine, t_vec *pos)
{
	if (engine->info.collected == engine->map->disks
		&& is_there(engine->map, pos, EXIT))
	{
		printf("\n%sYou've won!%s\n", HGRN, END);
		engine->info.status = WIN;
	}
}

void	check_lose(t_engine *engine, t_vec *pos, t_vec *epos)
{
	if (pos->x == epos->x && pos->y == epos->y)
	{
		if (engine->info.status != LOSE)
			printf("\n%sYou've lost!%s\n", HRED, END);
		engine->info.status = LOSE;
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

void	player_turn(t_engine *engine, t_info *info, t_vec d)
{
	t_vec	newpos;
	t_vec	*ppos;

	ppos = &engine->map->ppos;
	vec_set(&newpos, ppos->x + d.x, ppos->y + d.y);
	if ((d.x || d.y) && is_there(engine->map, &newpos, WALL))
		return ;
	vec_assign(ppos, &newpos);
	try_collect_disk(engine->map, &newpos, &engine->info);
	check_win(engine, &newpos);
	info->walks++;
	log_walk(info);
}

void	take_turn(t_engine *engine, t_vec d)
{
	player_turn(engine, &engine->info, d);
	enemies_turn(engine, engine->map, &engine->info);
}
