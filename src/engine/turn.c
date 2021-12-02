/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 09:59:23 by youkim            #+#    #+#             */
/*   Updated: 2021/12/02 10:00:27 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	try_collect_disk(t_map *map, t_vec *pos)
{
	if (!is_there(map, pos, DISK))
		return ;
	map->disks--;
	map->grid[pos->y][pos->x] = GROUND;
	printf("\n%syou've collected a disk!%s\n", HGRN, END);
}

static void	check_win(t_engine *engine, t_vec *pos)
{
	if (engine->map->disks == 0 && is_there(engine->map, pos, EXIT))
	{
		printf("\n%sYou've won!%s\n", HGRN, END);
		end_game(0, engine);
	}
}

void	take_turn(t_engine *engine, int dx, int dy)
{
	t_vec	*ppos;
	t_vec	newpos;

	ppos = &engine->map->ppos;
	vec_set(&newpos, ppos->x + dx, ppos->y + dy);
	if (is_there(engine->map, &newpos, WALL))
		return ;
	try_collect_disk(engine->map, &newpos);
	vec_assign(ppos, &newpos);
	check_win(engine, &newpos);
	log_walk(&engine->info);
	engine->info.walks++;
}
